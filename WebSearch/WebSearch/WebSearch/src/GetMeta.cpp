#include <ctime>
#include <set>
#include <cmath>
#include <string>
#include <time.h> 
#include <fstream>

//#include "getmeta.h"
//#include "json/json.h"

#include "../include/GetMeta.h"
#include "../include/json/json.h"


using namespace std;
using namespace Json;

string Trim(string& tempStr)
{
	if(tempStr.length() == 0)
	{
		return tempStr;
	}

	string str2;
	for ( int i = 0; i != tempStr.length(); ++i)
	{
		if ( tempStr[i] != ' ' )
			str2 += tempStr[i];
	}
	return str2;
}

bool FormatTime2(const char * szTime, time_t* time1)  
{  
    struct tm tm1;  
	int value;
  
    value = sscanf(szTime, "%4d-%2d-%2d",      
          &tm1.tm_year,   
          &tm1.tm_mon,   
          &tm1.tm_mday   
         );  
          
	if(value<3)
		return false;
	tm1.tm_hour = 0;
	tm1.tm_min = 0;
	tm1.tm_sec = 0;

    tm1.tm_year -= 1900;  
     tm1.tm_mon --;  
  
  
    tm1.tm_isdst=-1;  
    
    *time1 = mktime(&tm1);  
    return true;  
}  



bool GetMetaResult(string sKeyWords, MetaResult &metaResult)
{
	string SrcFile;
	SrcFile = "src/source.txt";
	ifstream infile(SrcFile.c_str());
	string hour ;
	string minute;
	string second ;

	getline(infile,hour);
	getline(infile,minute);
	getline(infile,second);
//	cout<<hour<<" "<<minute<<" "<<second<<" "<<endl;

	CGetMeta getMeta;
	string sRsltMeta;
	if (!getMeta.WorkThread( sKeyWords, sRsltMeta))
		return false;

	Reader reader;
	Value root;
	if (reader.parse(sRsltMeta, root))
	{
		metaResult.totalnum = root["totalnum"].asInt();
		const Value arrayMetaData = root["metadata"];
		int num = arrayMetaData.size();
		string temp;
		for (int i = 0; i < num; ++i)
		{
			MetaData metaData;

			temp = arrayMetaData[i]["pubtime"].asString();
			temp = Trim(temp);


			time_t timenow;
			time(&timenow);
			int timenumber;

			if(temp == ""|| temp == " ")
			{
			//	cout<<i<<"\tempty"<<endl;
				continue;
			}
	
			if(temp.find(hour)<temp.length())
			{
	//			cout<<temp<<endl;
				sscanf(temp.c_str(),"%d",&timenumber);
				metaData.pubtime = timenow - timenumber * 3600;		
			}
			else if(temp.find(minute)<temp.length())
			{
	//			cout<<temp<<endl;
				sscanf(temp.c_str(),"%d",&timenumber);
				metaData.pubtime = timenow - timenumber * 60;
			}
			else if(temp.find(second)<temp.length())
			{
	//			cout<<temp<<endl;
				sscanf(temp.c_str(),"%d",&timenumber);
				metaData.pubtime = timenow - timenumber * 1;
			}
			else
			{
				bool reading;
				reading = FormatTime2(temp.c_str(),&metaData.pubtime);
				if(reading == false)
				{
			//		cout<<i<<"\twrong format!"<<endl;
					continue;
				}
		//		strptime(temp.c_str(), fmt, &tmpubtime);
				//pubtime = mktime(&tmpubtime);
			}

		//	cout<<i<<"\t"<<ctime(&metaData.pubtime)<<endl;

			metaData.title = arrayMetaData[i]["title"].asString();
			metaData.url = arrayMetaData[i]["url"].asString();
			metaData.site = arrayMetaData[i]["site"].asString();
			metaData.abstract = arrayMetaData[i]["abstract"].asString();
			metaData.engine = arrayMetaData[i]["engine"].asString();
			
			metaResult.metaDatas.push_back(metaData);
		}
		metaResult.totalnum = metaResult.metaDatas.size();
	}
	else
		return false;

	return true;
}

static bool Test()
{
	MetaResult metaResult;
	if (GetMetaResult("html", metaResult))
		cout<<metaResult.totalnum<<endl;
}

