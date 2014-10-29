#include <algorithm>
#include <fstream>
#include <time.h> 

#include <vector>

#include "SimiCompare.h"

using namespace std;

vector<MetaData> SimiCompare::FilterAnalyze(string sKeyWords)
{
	KeyWords = sKeyWords;
	bool getMeta;
	
	getMeta = GetMetaResult(KeyWords, TotalReturnResult); 	
	if(getMeta == false)
	{
		cout<<"false Meta"<<endl;
		return finalResults;
	}

	if(TotalReturnResult.metaDatas.size()==0)
	{
		cout<<"No Data Return!"<<endl;
		return finalResults;
	}	

	
	vector<string> TotalTitles;
	vector<string> TotalAbstracts;
	cout<<TotalReturnResult.totalnum<<" "<<TotalReturnResult.metaDatas.size()<<endl;
	for(int i = 0;i<TotalReturnResult.totalnum;i++)
	{
		TotalTitles.push_back(TotalReturnResult.metaDatas[i].title);
		TotalAbstracts.push_back(TotalReturnResult.metaDatas[i].abstract);
	}	



	////////////////////////start/////////////////////////
	vector<double> SimiTitles = ListSimiCamp(KeyWords,TotalTitles);
	

	int LargestIndex = FindLargest(SimiTitles);

	if(SimiTitles[LargestIndex] < SIMITHRESHOLD)
	{
		vector<double> SimiAbstracts = ListSimiCamp(KeyWords,TotalAbstracts);
		LargestIndex = FindLargest(SimiAbstracts);
	}

	cout<<"The Largest Similar index is:"<<LargestIndex<<endl;

	vector<double> SimiAbstractsBetween = ListSimiCamp(TotalReturnResult.metaDatas[LargestIndex].abstract,TotalAbstracts);
	vector<MetaData> finalResults = FilterByThreshold(SimiAbstractsBetween);

	int size = finalResults.size();

	cout<<"Size After Threshold:"<<size<<endl;
	sort(finalResults.begin(),finalResults.begin()+size,comparep);

	reverse(finalResults.begin(),finalResults.begin()+size);


	//////////////////////////end////////////////////////////
	return finalResults;
}


vector<double> SimiCompare::ListSimiCamp(string& key,vector<string>& Lists)
{
	vector<double> Simi;
	int returnResult;

	//SimiForTitle
	//////////////////////////////////////////!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!Problem see TextSimAPITest
	returnResult = Sim_Get(handle, key, Lists, Simi);
	if (returnResult = 0)
	{
		cout<<"ListSimiFail"<<endl;
        	perror("SimCalcGetFailed\n");
       		exit(EXIT_FAILURE);
	}
	////////////////////////////////////////////////////////////////////////////////

	return Simi;

}

//TODO
int SimiCompare::FindLargest (vector<double>& Numbers)
{
	int maxIndex;
	//!!!!!!!!!!!!!!!!test
	double maxValue = -1;
	for(unsigned int i = 0;i < Numbers.size();i++)
	{
		if(Numbers[i]>maxValue)
		{
			maxValue = Numbers[i];
			maxIndex = i;
		}
	}
	return maxIndex;
}

vector<MetaData> SimiCompare::FilterByThreshold(vector<double> & Numbers)
{
	vector<MetaData> result;
	for(unsigned int i = 0;i<Numbers.size();i++)
	{
		if(Numbers[i]>SIMITHRESHOLD)
		{
			result.push_back(TotalReturnResult.metaDatas[i]);
		}
	}
	return result;
}
