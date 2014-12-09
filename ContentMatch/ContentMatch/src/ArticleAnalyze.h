#ifndef _ARTICLE_ANALYZE_H_
#define _ARTICLE_ANALYZE_H_

#include <iostream>
#include <vector>
#include "SentenceSplit.h"
#include "SentAndPosition.h"
#include <sys/types.h>
#include "../include/SimHashAPI.h"

using namespace std;

class ArticleAnalyze
{
public:
	 ArticleAnalyze(void)
	{
		SentenceSplit sp = SentenceSplit();
		HaveBeenMarked = vector<bool>();
	}
    ArticleAnalyze(string inputArticle,SH_H * thehandle)
	{
		handle = thehandle;
		init(inputArticle);
		SplitAndCalcSimHash();
	}

    virtual ~ArticleAnalyze(void)
    { }

public:
    void init(string inputArticle);
    bool SplitAndCalcSimHash();
	void InitiateMarkedLabel(void);
	
public:
    char filename[200];
    vector<SentAndPosition> RetSentAndPos;
	vector<uint64_t> SimHashValue; //以位计算，所以还需要考虑一下数据类型
	vector<bool> HaveBeenMarked;//All Initiate to False;
	SH_H * handle;

private:
	SentenceSplit sp;

};














#endif