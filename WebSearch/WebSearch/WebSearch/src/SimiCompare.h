#ifndef _SIMI_COMPARE_H_
#define _SIMI_COMPARE_H_

#include <iostream>
#include <vector>
#include "../include/GetMeta.h"
#include "../include/TextSimilarityAPI.h"
#include <time.h>

#define SIMITHRESHOLD 0.85
using namespace std;

bool comparep(const MetaData a, const MetaData b)
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
	SimiCompare(string sKeyWords)
	{
		KeyWords = sKeyWords;
	}
	~SimiCompare(void)
	{}

	vector<MetaData> FilterAnalyze(void);

private:
	vector<double> ListSimiCamp(string&,vector<string>&);
	int FindLargest(vector<double>&);
	vector<MetaData> FilterByThreshold(vector<double>&);

	struct MetaResult TotalReturnResult;
	string KeyWords;
	vector<MetaData> finalResults;
	SIM_H * handle;
};

#endif
