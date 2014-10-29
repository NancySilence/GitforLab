#include<iostream>
#include "ArticleAnalyze.h"
#include "CompareArticles.h"
#include "ModifyResult.h"
#include <string>
#include <ctime>
#include <time.h> 
#include <fstream>

using namespace std;

int main(void)
{

	CompareArticles ca = CompareArticles();
	vector<ModifyResult> finalResult = ca.GetDiff("test","anothertest");

	time_t tt;
	tt = time(NULL);
	tm* t= localtime(&tt);
	char fileName[150];
	sprintf(fileName,"./result/Output_%d-%02d-%02d_%02d-%02d-%02d.txt",
		t->tm_year + 1900,
		t->tm_mon + 1,
		t->tm_mday,
		t->tm_hour,
		t->tm_min,
		t->tm_sec
		);
	
	ofstream fout;
	fout.open(fileName);
	string temp;
	fout<<fileName<<endl;	
	fout<<finalResult.size()<<endl;


	for(unsigned int i = 0;i<finalResult.size();i++)
	{
		if(finalResult[i].type == 0)
		{
			temp = "Add:\n\tB's Sentence Index\t"+finalResult[i].IndexB;
			temp += "\n\t\t"+finalResult[i].SentenceB;
		}
		else if(finalResult[i].type == 1)
		{
			temp = "Delete:\n\tA's Sentence Index\t"+finalResult[i].IndexA +finalResult[i].SentenceA;
			temp += "\n\t\t"+finalResult[i].SentenceA;
		}
		else if(finalResult[i].type == 1)
		{
			temp = "Modify:\n\tA's Sentence Index\t"+finalResult[i].IndexA;
			temp += "\n\t\t"+finalResult[i].SentenceA;
			temp += "\n\tB's Sentence Index\t"+finalResult[i].IndexB;
			temp += "\n\t\t"+finalResult[i].SentenceB;
		}
		fout <<temp<<endl; 
	}
	
	fout.close();

}
