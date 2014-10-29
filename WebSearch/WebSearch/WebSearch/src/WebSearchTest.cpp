#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>
#include <time.h> 
//#include "GetMeta.h"
//#include "SimiCompare.h"
//#include "TextSimilarityAPI.h"

#include "../include/GetMeta.h"
#include "SimiCompare.h"
#include "../include/TextSimilarityAPI.h"

using namespace std;


int main(void)
{
	string newKeyword;
	
	string inputFileName;
	inputFileName = "input.txt";
	ifstream infile(inputFileName.c_str());
	getline(infile,newKeyword);

	cout<<"Keyword is: "<<newKeyword<<endl;
	SimiCompare newSimi = SimiCompare();
	vector<MetaData> finalResult = newSimi.FilterAnalyze(newKeyword);

	time_t tt;
	tt = time(NULL);
	tm* t= localtime(&tt);
	char fileName[150];
	sprintf(fileName,"./result/Output_%d-%02d-%02d_%02d-%02d-%02d_KeyWord-%s.txt",
		t->tm_year + 1900,
		t->tm_mon + 1,
		t->tm_mday,
		t->tm_hour,
		t->tm_min,
		t->tm_sec,
		newKeyword.c_str()
		);
	
	ofstream fout;
	fout.open(fileName);
	string temp;
	fout<<fileName<<endl;	
	fout<<finalResult.size()<<endl;


	for(unsigned int i = 0;i<finalResult.size();i++)
	{
		temp = finalResult[i].title+"\n\t"+ctime(&finalResult[i].pubtime)+"\n\t\t"+finalResult[i].abstract;
		fout <<temp<<endl; 
	}
	
	fout.close();

	return 0;
}

