#ifndef _COMPARE_ARTICLES_H_
#define _COMPARE_ARTICLES_H_


#include <iostream>
#include "ArticleAnalyze.h"
#include "ModifyResult.h"
#include "../include/SimHashAPI.h"
using namespace std;
#define DISTTHRESHOLD 3
typedef unsigned __int64	uint64_t;



class CompareArticles
{
public:
    CompareArticles(void)
    {
		char ConfigFile[40] = "config/simhash.config.xml";
		int returnResult;
	
		returnResult = SH_Init(ConfigFile,  &handle);
		if (returnResult = 0)
		{
			cout<<"SimHash init faied"<<endl;
       		perror("SimHashInitFailed\n");
       		exit(EXIT_FAILURE);
		}
	}

    virtual ~CompareArticles(void)
    {
		int returnResult = SH_Exit(handle);

		if (returnResult = 0)
		{
       		perror("SimHashExitFailed\n");
       		exit(EXIT_FAILURE);
		}

	}

public:
    vector<ModifyResult> GetDiff(string inputArticleA,string inputArticleB);


private:
	int CalcSimHashDistance(uint64_t A,uint64_t B);
	void InitiateMarkedLabel(ArticleAnalyze);

private:
    ArticleAnalyze FormerArticle, LaterArticle;
    vector<ModifyResult> FinalResult;
	SH_H * handle;
};


#endif