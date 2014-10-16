#ifndef _SIMI_COMPARE_H_
#define _SIMI_COMPARE_H_

#include <iostream>
#include <vector>
#include "../include/GetMeta.h"
#include "../include/TextSimilarityAPI.h"

#define SIMITHRESHOLD 0.85
using namespace std;

bool comparep(const MetaData a, const MetaData b)
{
	return (a.pubtime)<(b.pubtime);
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
	vector<double> ListSimiCamp(string,vector<string>);
	int FindLargest(vector<double>);
	vector<MetaData> FilterByThreshold(vector<double>);

	struct MetaResult TotalReturnResult;
	string KeyWords;
	vector<MetaData> finalResults;
};

#endif
