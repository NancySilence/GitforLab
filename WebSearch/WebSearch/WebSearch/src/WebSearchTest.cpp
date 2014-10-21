#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>

#include "../include/GetMeta.h"
#include "SimiCompare.h"
#include "../include/TextSimilarityAPI.h"

using namespace std;


int main(void)
{
	SimiCompare newSimi = SimiCompare("Air Pollution is a very serious problem in the current year");
	vector<MetaData> finalResult = newSimi.FilterAnalyze();

	time_t tt;
	tt = time(NULL);
	tm* t= localtime(&tt);
	char fileName[150];
	sprintf(fileName,"Output:%d-%02d-%02d %02d:%02d:%02d KeyWord:%s",
		t->tm_year + 1900,
		t->tm_mon + 1,
		t->tm_mday,
		t->tm_hour,
		t->tm_min,
		t->tm_sec,
		"AirPollution"
		);
	ofstream fout(fileName);
	string temp;
	for(int i = 0;i<finalResult.size();i++)
	{
		temp = finalResult[i].title+" "+finalResult[i].pubtime+" "+finalResult[i].abstract;
		fout <<temp<<endl; // fout用法和cout一致, 不过是写到文件里面去
	}
	

	return 0;
}

