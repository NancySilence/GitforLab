#ifndef _SENTENCE_SPLIT_H_
#define _SENTENCE_SPLIT_H_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include "SentAndPosition.h"
using namespace std;


class SentenceSplit
{
public:
	SentenceSplit(void)
	{
		string SrcFile;
		SrcFile = "src/splitPunct.txt";
		ifstream infile(SrcFile.c_str());
		punct.clear();

		while(!infile.eof() ) 
		{
			string temp;
			getline(infile,temp);
			punct.push_back(temp); 
		}
		punct.push_back("\n");
	}

	std::vector<SentAndPosition>  split(std::string& InputString);
private:
	void findIndex(string & str,string &source,vector<int>& indexVector);
	string trim(string str);

	vector<string> punct;
};

#endif