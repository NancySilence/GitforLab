#include <iostream>
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
	string SrcFile;
	SrcFile = "source.txt";
	ifstream infile(SrcFile.c_str());
	std::stringstream buffer;
	buffer<<infile.rdbuf();
	std::string contents(buffer.str());

	string another;
	another = "another.txt";
	ifstream inin(another.c_str());
	std::stringstream anotherbuffer;
	anotherbuffer<<inin.rdbuf();
	std::string anothercontent(anotherbuffer.str());


	CompareArticles ca = CompareArticles();
	vector<ModifyResult> finalResult = ca.GetDiff(contents,anothercontent);

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
	fout<<fileName<<endl;	
	fout<<finalResult.size()<<endl;


	for(unsigned int i = 0;i<finalResult.size();i++)
	{
		if(finalResult[i].type == 0)
		{
			fout<<finalResult[i].type<<"  Add"<<endl;
			fout<<"\t"<<finalResult[i].IndexB<<"\t"<<finalResult[i].SentBStart<<"\t"<<finalResult[i].SentBLength<<endl;
			fout<<"\t"<<finalResult[i].SentenceB<<endl;
		}
		else if(finalResult[i].type == 1)
		{
			fout<<finalResult[i].type<<"  Delete"<<endl;
			fout<<"\t"<<finalResult[i].IndexA<<"\t"<<finalResult[i].SentAStart<<"\t"<<finalResult[i].SentALength<<endl;
			fout<<"\t"<<finalResult[i].SentenceA<<endl;
		}
		else if(finalResult[i].type == 2)
		{
			fout<<finalResult[i].type<<"  Modify"<<endl;
			fout<<"\t"<<" A:"<<finalResult[i].IndexA<<"\t"<<finalResult[i].SentAStart<<"\t"<<finalResult[i].SentALength<<endl;
			fout<<"\t"<<finalResult[i].SentenceA<<endl;
			fout<<"\t"<<" B:"<<finalResult[i].IndexB<<"\t"<<finalResult[i].SentBStart<<"\t"<<finalResult[i].SentBLength<<endl;
			fout<<"\t"<<finalResult[i].SentenceB<<endl;
		}
	}
	
	fout.close();

}
