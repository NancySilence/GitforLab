#ifndef _ARTICLE_ANALYZE_H_
#define _ARTICLE_ANALYZE_H_
typedef unsigned __int64	uint64_t;

#include <iostream>
#include <vector>
using namespace std;

class ArticleAnalyze
{
public:
	 ArticleAnalyze(void)
	{
	}
    ArticleAnalyze(string inputArticle,SH_H * thehandle)
	{
		handle = thehandle;
		init(inputArticle);
	}

    virtual ~ArticleAnalyze(void)
    { }

public:
    bool init(string inputArticle);
    bool SplitAndCalcSimHash();
	
public:
    char filename[200];
    vector<string> EachSentence;
	vector<uint64_t> SimHashValue; //以位计算，所以还需要考虑一下数据类型
	vector<bool> HaveBeenMarked;//All Initiate to False;
	SH_H * handle;


};














#endif