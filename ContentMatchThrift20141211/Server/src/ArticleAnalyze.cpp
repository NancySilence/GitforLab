#include "ArticleAnalyze.h"
#include "../include/SimHashAPI.h"
#include <string>
#include "SentenceSplit.h"
#include "SentAndPosition.h"

void ArticleAnalyze::init(string inputArticle)
{
	vector<SentAndPosition> RetResult = vector<SentAndPosition>();
	RetSentAndPos = sp.split(inputArticle);
}


bool ArticleAnalyze::SplitAndCalcSimHash()
{
	uint64_t HashResult;
	SimHashValue.clear();
	for(int ix = 0;ix <RetSentAndPos.size();ix++)
	{
		string tmp = RetSentAndPos[ix].Sentence;
		int returnResult = SH_Get(handle, tmp, HashResult);
		if (returnResult = 0)
		{
			cout<<"SimHashGetFailed!"<<endl;
       		perror("SimHashGetFailed\n");
       		exit(EXIT_FAILURE);
		}
		SimHashValue.push_back(HashResult);
	}
	return true;
}

void ArticleAnalyze::InitiateMarkedLabel(void)
{
	HaveBeenMarked.clear();
	for(int i =0;i<SimHashValue.size();i++)
	{
		bool insert = false;
		HaveBeenMarked.push_back(insert);
	}

}

