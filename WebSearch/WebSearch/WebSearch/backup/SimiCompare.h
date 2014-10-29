#ifndef _SIMI_COMPARE_H_
#define _SIMI_COMPARE_H_

#include <iostream>
#include <vector>

#include "../include/GetMeta.h"
#include "../include/TextSimilarityAPI.h"

#include <ctime>

#define SIMITHRESHOLD -2

using namespace std;

inline bool comparep(const MetaData &a, const MetaData &b)
{
	char fmt[] = "%Y-%m-%d-%H:%M:%S";
	struct tm TimeA,TimeB;
	strptime(a.pubtime.c_str(), fmt, &TimeA);
	strptime(b.pubtime.c_str(), fmt, &TimeB);

	return (difftime(mktime(&TimeA), mktime(&TimeB)) < 0 );
}

class SimiCompare
{
public:
	SimiCompare(void)
	{
		char ConfigFile[40] = "config/sim.config.xml";
		int returnResult;
		returnResult = Sim_Init(ConfigFile, &handle);
		if (returnResult = 0)
		{
			cout<<"simicompare init failed"<<endl;
       			perror("SimCalcInitFailed\n");
       			exit(EXIT_FAILURE);
		}
	}
	~SimiCompare(void)
	{
		//exit
		int returnResult = Sim_Exit(handle);
		if (returnResult = 0)
		{
       		perror("SimCalcExitFailed\n");
       		exit(EXIT_FAILURE);
		}
	}

	vector<MetaData> FilterAnalyze(string sKeyWords);

private:
	vector<double> ListSimiCamp(string&, vector<string>&);
	int FindLargest(vector<double>&);
	vector<MetaData> FilterByThreshold(vector<double>&);

	struct MetaResult TotalReturnResult;
	string KeyWords;
	vector<MetaData> finalResults;
	SIM_H * handle;
};

#endif
