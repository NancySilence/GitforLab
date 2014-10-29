#include "ArticleAnalyze.h"
#include "../include/SimHashAPI.h"
#include <string>

bool ArticleAnalyze::SplitAndCalcSimHash()
{
	//Split task

	//for each string.
	/*
	
	//for each string.
	char ConfigFile[40] = "config/simhash.config.xml";
	uint64_t HashResult;
	int returnResult;
	SH_H * handle;

	//Iteration Start
	string  testSim= "Start from something new";
	
	returnResult = SH_Init(ConfigFile,  &handle);
	cout<<"InitResult:"<<returnResult<<endl;

	returnResult = SH_Get(handle, testSim, HashResult);
	cout<<"GetResult:"<<returnResult<<endl;
	cout<<endl<<"HashResult:!!"<<HashResult<<endl;
	returnResult = SH_Exit(handle);

	cout<<"ExitResult:"<<returnResult<<endl;
	return 0;
	
	
	
	
	*/
	
	uint64_t HashResult;
	string  testSim= "Start from something new";
	
	//Iteration Start
	int returnResult = SH_Get(handle, testSim, HashResult);
	if (returnResult = 0)
	{
		cout<<"SimHashGetFailed!"<<endl;
       	perror("SimHashGetFailed\n");
       	exit(EXIT_FAILURE);
	}
	EachSentence.push_back(testSim);
	SimHashValue.push_back(HashResult);
	//Iteration End

	return true;
}