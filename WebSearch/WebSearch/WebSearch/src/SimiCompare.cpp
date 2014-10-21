#include "SimiCompare.h"
#include <algorithm>
#include <fstream>

#include <vector>

using namespace std;

vector<MetaData> SimiCompare::FilterAnalyze(void)
{
	bool getMeta;
	
	getMeta = GetMetaResult(KeyWords, TotalReturnResult); 	
	if(getMeta == false)
		return finalResults;

	vector<string> TotalTitles;
	vector<string> TotalAbstracts;

	for(int i = 0;i<TotalReturnResult.totalnum;i++)
	{
		TotalTitles.push_back(TotalReturnResult.metaDatas[i].title);
		TotalAbstracts.push_back(TotalReturnResult.metaDatas[i].abstract);
	}	

	//////////////////////////////////////////////////////////////////////////
	//Calculate about title
	//Init
	char ConfigFile[40] = "config/sim.config.xml";
	int returnResult;
	returnResult = Sim_Init(ConfigFile,  &handle);
	if (returnResult = 0)
	{
       	perror("SimCalcInitFailed\n");
       	exit(EXIT_FAILURE);
	}



	////////////////////////start/////////////////////////
	vector<double> SimiTitles = ListSimiCamp(KeyWords,TotalTitles);
	
	int LargestIndex = FindLargest(SimiTitles);

	if(SimiTitles[LargestIndex] < SIMITHRESHOLD)
	{
		vector<double> SimiAbstracts = ListSimiCamp(KeyWords,TotalAbstracts);
		LargestIndex = FindLargest(SimiAbstracts);

	}

	vector<double> SimiAbstractsBetween = ListSimiCamp(TotalReturnResult.metaDatas[LargestIndex].abstract,TotalAbstracts);
	vector<MetaData> finalResults = FilterByThreshold(SimiAbstractsBetween);

	int size = finalResults.size();
	sort(finalResults.begin(),finalResults.begin()+size,comparep);

	reverse(finalResults.begin(),finalResults.begin()+size);


	//////////////////////////end////////////////////////////

	//exit
	returnResult = Sim_Exit(handle);
	if (returnResult = 0)
	{
       	perror("SimCalcExitFailed\n");
       	exit(EXIT_FAILURE);
	}

	return finalResults;


}


vector<double> SimiCompare::ListSimiCamp(string& key,vector<string>& Lists)
{
	vector<double> Simi;
	int returnResult;

	//SimiForTitle
	//////////////////////////////////////////!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!Problem see TextSimAPITest
	returnResult = Sim_Get(handle, key, Lists,Simi);
	if (returnResult = 0)
	{
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
	for(int i = 0;i<Numbers.size();i++)
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
	for(int i = 0;i<Numbers.size();i++)
	{
		if(Numbers[i]>SIMITHRESHOLD)
		{
			result.push_back(TotalReturnResult.metaDatas[i]);
		}
	}
	return result;
}
