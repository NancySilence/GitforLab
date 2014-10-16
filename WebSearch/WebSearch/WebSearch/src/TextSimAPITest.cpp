#include <iostream>
#include <fstream>
#include <vector>

#include "../include/TextSimilarityAPI.h"

using namespace std;

static void Test()
{
	SIM_H *h;
	if (0 == Sim_Init("config/sim.config.xml", &h))
	{
		cout<<"Failed to  Init"<<endl;
		return;
	}
cout<<"Init Done"<<endl;

       vector<string> texts;
	fstream fInFile;
	fInFile.open("data/train.dat", ios::in);
	string line;
	while (getline(fInFile,line))
		texts.push_back(line);
	fInFile.close();
	texts.resize(100);

       vector<double> sims;
	if (1 == Sim_Get(h, texts[0], texts, sims))
		cout<<"Done"<<endl;
	else
		cout<<"Failed"<<endl;
	
	for (uint32_t  i = 0; i < sims.size(); i++)
		cout<< i <<" "<<sims[i]<<endl;

	Sim_Exit(h);
}

int main()
{
	Test();
	return 0;
}

