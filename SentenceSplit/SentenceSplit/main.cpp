#include <iostream>
#include <vector>
#include "SentenceSplit.h"

using namespace std;

int main(void)
{
	string SrcFile;
	SrcFile = "source.txt";
	ifstream infile(SrcFile.c_str());
	std::stringstream buffer;
	buffer<<infile.rdbuf();
	std::string contents(buffer.str());

	vector<SentAndPosition> RetResult = vector<SentAndPosition>();
	SentenceSplit sp = SentenceSplit();

	RetResult = sp.split(contents);

	ofstream fout;
	fout.open("result.txt");
	string temp;

	temp = "start\n";
	for(int ix = 0;ix<RetResult.size();ix++)
	{
		fout<<"\t"<<RetResult[ix].StartPosition<<"\t"<<RetResult[ix].Length<<endl;
		fout<<RetResult[ix].Sentence<<endl;
		fout<<"****************************************"<<endl;
	}
	fout.close();

	return 0;

}