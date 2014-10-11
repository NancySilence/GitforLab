#include "CompareArticles.h"
#include <limits.h>
#include <vector>

//done
vector<ModifyResult>   CompareArticles::Processing(void)
{

	int AIter;
	int BIter;
	int tempCompare;//Temp distance result between A and B
	int MiniDist; //Min Distance from certain B to every A
	int MiniAIndex; // the Min value index of A

	//InitiateAllA'sLabel to False;
	
	InitiateMarkedLabel(FormerArticle);

	for ( int BIter = 0 ;BIter < LaterArticle.SimHashValue.size() ;BIter++ )

	{
		MiniDist = INT_MAX;
		for(AIter = 0; AIter < FormerArticle.SimHashValue.size();AIter++)
		{
			//true means it has already been marked.
			if(FormerArticle.HaveBeenMarked[AIter] == false)
			{
				tempCompare = CalcSimHashDistance(LaterArticle.SimHashValue[BIter],FormerArticle.SimHashValue[AIter]);
				if(tempCompare<MiniDist)
				{
					MiniDist = tempCompare;
					MiniAIndex = AIter;
				}
				if(tempCompare == 0)
					break;
			}
		}

		//type: 0 B add;  1 A delete ; 2 A modified to B
		if(MiniDist == 0)
		{
			//no modify
			//Needn't add modify record
			FormerArticle.HaveBeenMarked[MiniAIndex] = true;
		}
		else if(MiniDist<DISTTHRESHOLD)
		{
			//Modify
			FormerArticle.HaveBeenMarked[MiniAIndex] = true;
			ModifyResult* tempModify = new ModifyResult();
			tempModify->type = 2;
			tempModify->IndexA = MiniAIndex;
			tempModify->IndexB = BIter;
			FinalResult.push_back(*tempModify);
		}
		else
		{
			//Adding
			//A is not marked in adding case
			ModifyResult* tempAdding = new ModifyResult();
			tempAdding->type = 0;
			tempAdding->IndexB = BIter;
			FinalResult.push_back(*tempAdding);
		}
	}

	//Iteration for A check delete
	for(AIter = 0; AIter < FormerArticle.SimHashValue.size();AIter++)
	{
		//true means it has already been marked.
		if(FormerArticle.HaveBeenMarked[AIter] == false)
		{
			ModifyResult* tempDelete = new ModifyResult();
			tempDelete->type = 1;
			tempDelete->IndexA = AIter;
			FinalResult.push_back(*tempDelete);
		}
	}

	return FinalResult;
}


int  CompareArticles::CalcSimHashDistance(int Numb1,int Numb2)
{
	return 0;
}

//done!
void CompareArticles::InitiateMarkedLabel(ArticleAnalyze A)
{
	A.HaveBeenMarked.clear();
	for(int i =0;i<A.SimHashValue.size();i++)
	{
		A.HaveBeenMarked.push_back(false);
	}
}