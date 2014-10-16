#ifndef _COMPARE_ARTICLES_H_
#define _COMPARE_ARTICLES_H_


#include <iostream>
#include "ArticleAnalyze.h"
#include "ModifyResult.h"
using namespace std;
#define DISTTHRESHOLD 3
typedef unsigned __int64	uint64_t;



class CompareArticles
{
public:
    CompareArticles(ArticleAnalyze A,ArticleAnalyze B)
    {
		FormerArticle = A;
		LaterArticle = B;	
	}

    virtual ~CompareArticles(void)
    {
	}

public:
    vector<ModifyResult> Processing(void);

private:
	int CalcSimHashDistance(uint64_t A,uint64_t b);
	void InitiateMarkedLabel(ArticleAnalyze);

private:
    ArticleAnalyze FormerArticle, LaterArticle;
    vector<ModifyResult> FinalResult;

};


#endif