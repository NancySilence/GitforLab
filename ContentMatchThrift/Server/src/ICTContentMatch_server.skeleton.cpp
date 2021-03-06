// This autogenerated skeleton file illustrates how to build a server.
// You should copy it to another filename to avoid overwriting it.

#include "ArticleAnalyze.h"
#include "CompareArticles.h"
#include "ModifyResult.h"
#include "Logger.h"

#include <string>
#include <ctime>
#include <time.h> 
#include <fstream>
#include <iostream>
#include <list>

#include "ICTContentMatch.h"

#include <protocol/TBinaryProtocol.h>
#include <server/TSimpleServer.h>
#include <transport/TServerSocket.h>
#include <transport/TBufferTransports.h>

#include <concurrency/ThreadManager.h>
#include <server/TNonblockingServer.h>
#include <concurrency/PosixThreadFactory.h>
#include <server/TThreadPoolServer.h>
#include <server/TThreadedServer.h>

using namespace::std;
using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;
using namespace ::apache::thrift::concurrency;

using boost::shared_ptr;

using namespace  ::ContentMatchService;

CLogger *g_logger;

class ICTContentMatchHandler : virtual public ICTContentMatchIf {
 public:
  ICTContentMatchHandler() {
    // Your initialization goes here

	CAHandler = new CompareArticles();
	if(CAHandler->currentState == 0)
	{
		string sMsg = "ICT ContentMatch Init Failed";
		g_logger->LogError("301", sMsg);
		m_bIsReady  =false;
		return;
	}
	else
	{
		string sMsg = "ICT ContentMatch Init Done";
		g_logger->LogInfo("001", sMsg);	
		m_bIsReady  =true;
	}
  }
  

  void GetDiff(Batch_Result_Info& _return, const std::string& content_source, const std::string& content_target) {
    // Your implementation goes here
    printf("GetDiff\n");
	vector<ModifyResult> finalResult = CAHandler->GetDiff(content_source,content_target);
	_return.status = 200;
	if(finalResult.size()==0)
	{
		string sMsg = string("No Diff Returned\n");
		g_logger->LogWarn("101", sMsg);
		_return.status = 500;
		return ;
	}
	_return.result_info_list.clear();
	
	for(unsigned int i = 0;i<finalResult.size();i++)
	{
		Match_Result MR;
		MR.type = finalResult[i].type;
		MR.source_start_offset = finalResult[i].IndexA;
		MR.source_length = finalResult[i].SentALength;
		MR.target_start_offset = finalResult[i].IndexB;
		MR.target_length = finalResult[i].SentBLength;
		(_return.result_info_list).push_back(MR);
	}

	
	char msgBufferin[255];
	sprintf(msgBufferin, "ICT ContentMatch Find: %d Differences。", finalResult.size());
	string sMsg = msgBufferin;	
	g_logger->LogInfo("001", sMsg);	
  }
  
  bool isReady()
  {
	return m_bIsReady;
  }

  private:
  CompareArticles *CAHandler;
  bool m_bIsReady;

};

int main(int argc, char **argv) {
  int port = 9092;
  fstream fInFile;
  fInFile.open("./port.txt", ios::in);
  if (fInFile)
	fInFile>>port;
   
   fInFile.close();
   
   g_logger = new CLogger();
  g_logger->Init("ICTContentMatchService", LOG_TOFILE, "./log/", LOG_WITHTIME);
   
   ICTContentMatchHandler *CMH = new ICTContentMatchHandler();
   if(!CMH->isReady())
	return false;
   
   
  shared_ptr<ICTContentMatchHandler> handler(CMH);
  shared_ptr<TProcessor> processor(new ICTContentMatchProcessor(handler));
  shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

  char msgBuffer[255];
  sprintf(msgBuffer, "Starting ContentMatch Service, port : %d", port);
  string sMsg = msgBuffer;
  g_logger->LogInfo("001", sMsg);
  
  TThreadPoolServer* pServer = NULL;
  shared_ptr<ThreadManager> threadManager = ThreadManager::newSimpleThreadManager(100);
  shared_ptr<PosixThreadFactory> threadFactory = shared_ptr<PosixThreadFactory>(new PosixThreadFactory());
  threadManager->threadFactory(threadFactory);
  threadManager->start();
  
  pServer = new TThreadPoolServer(processor, serverTransport, transportFactory, protocolFactory, threadManager);
  pServer -> serve();
  
  sMsg = "Content Match Service Stopped";
  g_logger->LogInfo("001", sMsg);
  delete g_logger;

  return 0;
}

