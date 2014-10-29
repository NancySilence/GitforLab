#include "CompareArticles.h"
#include <limits.h>
#include <vector>

//done
vector<ModifyResult>   CompareArticles::GetDiff(string inputArticleA,string inputArticleB)
{

	int AIter;
	int BIter;
	int tempCompare;//Temp distance result between A and B
	int MiniDist; //Min Distance from certain B to every A
	int MiniAIndex; // the Min value index of A

	//InitiateAllA'sLabel to False;
	
	FormerArticle = ArticleAnalyze(inputArticleA,handle);
	LaterArticle =  ArticleAnalyze(inputArticleB,handle);	

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
			tempModify->SentenceA = FormerArticle.EachSentence[MiniAIndex];
			tempModify->SentenceB = LaterArticle.EachSentence[BIter];
			FinalResult.push_back(*tempModify);
		}
		else
		{
			//Adding
			//A is not marked in adding case
			ModifyResult* tempAdding = new ModifyResult();
			tempAdding->type = 0;
			tempAdding->IndexB = BIter;
			tempAdding->SentenceB = LaterArticle.EachSentence[BIter];
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
			tempDelete->SentenceA = FormerArticle.EachSentence[AIter];
			FinalResult.push_back(*tempDelete);
		}
	}

	return FinalResult;
}


int  CompareArticles::CalcSimHashDistance(uint64_t Numb1,uint64_t Numb2)
{
	uint64_t x;
	x = ~(Numb1^Numb2);


	//The rest job is to calculate the hamming weight of SameBits.
	const uint64_t m1  = 0x5555555555555555; //binary: 0101...
	const uint64_t m2  = 0x3333333333333333; //binary: 00110011..
	const uint64_t m4  = 0x0f0f0f0f0f0f0f0f; //binary:  4 zeros,  4 ones ...
	const uint64_t m8  = 0x00ff00ff00ff00ff; //binary:  8 zeros,  8 ones ...
	const uint64_t m16 = 0x0000ffff0000ffff; //binary: 16 zeros, 16 ones ...
	const uint64_t m32 = 0x00000000ffffffff; //binary: 32 zeros, 32 ones ...
	const uint64_t hff = 0xffffffffffffffff; //binary: all ones
	const uint64_t h01 = 0x0101010101010101; //the sum of 256 to the power of 0,1,2,3...
 

 
	//This uses fewer arithmetic operations than any other known  
	//implementation on machines with fast multiplication.
	//It uses 12 arithmetic operations, one of which is a multiply.
	
	x -= (x >> 1) & m1;             //put count of each 2 bits into those 2 bits
	x = (x & m2) + ((x >> 2) & m2); //put count of each 4 bits into those 4 bits 
	x = (x + (x >> 4)) & m4;        //put count of each 8 bits into those 8 bits 
	return (x * h01)>>56;  //returns left 8 bits of x + (x<<8) + (x<<16) + (x<<24) + ... 

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