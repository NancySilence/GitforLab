#ifndef _ARTICLE_ANALYZE_H_
#define _ARTICLE_ANALYZE_H_

#include <iostream>
#include <vector>
using namespace std;

class ArticleAnalyze
{
public:
    ArticleAnalyze(void)
	{
	}

    virtual ~ArticleAnalyze(void)
    { }

public:
    bool init(char *inputArticle);
    bool SplitAndCalcSimHash();
	
public:
    char filename[200];
    vector<string> EachSentence;
	vector<int> SimHashValue; //以位计算，所以还需要考虑一下数据类型
	vector<bool> HaveBeenMarked;//All Initiate to False;


};














#endif