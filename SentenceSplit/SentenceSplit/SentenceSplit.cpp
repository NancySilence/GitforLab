#include "SentenceSplit.h"

using namespace std;



string SentenceSplit::trim(string str)
{
	string erasetarget = "\r\t\n "+punct[0];
	str.erase(0, str.find_first_not_of(erasetarget)); 
	str.erase(str.find_last_not_of(erasetarget) + 1);
	return str;
}

void SentenceSplit::findIndex(string & str,string &source,vector<int>& indexVector)
{
	string temp,p;
	int lens = source.length();

	size_t last = 0;
	size_t index=str.find(source,0);  
    while (index!=std::string::npos)  
    {  
		indexVector.push_back(index+lens);  
        last=index+lens;  
        index=str.find(source,last);  
    }  
}

vector<SentAndPosition>  SentenceSplit::split(string& InputString)  
{  
	vector<int> indexVector=vector<int>();
	vector<SentAndPosition> returnVector = vector<SentAndPosition>();

	int ix;
	for(ix = 0;ix<punct.size();ix++)
	{
		findIndex(InputString,punct[ix],indexVector);
	}

	sort(indexVector.begin(),indexVector.end());

	size_t last = 0;
	size_t indexnow;

	for(ix = 1;ix<indexVector.size();ix++)
	{
		indexnow = indexVector[ix];
		if(indexnow == last)
			continue;
		string tmp = InputString.substr(last,indexnow-last);
		tmp = trim(tmp);
		if(tmp!=" "&&tmp!="\n"&&tmp!="")
		{
			SentAndPosition inner = SentAndPosition();
			inner.Sentence = tmp;
			inner.StartPosition = last;
			inner.Length = indexnow-last;
			returnVector.push_back(inner);
		}	
		last = indexnow;
	}
	
	if(indexVector[indexVector.size()-1]<InputString.size())
	{
		string tt = InputString.substr(last,InputString.size()-last);
		tt = trim(tt);
		if(tt!=" "&&tt!="\n"&&tt!="")
		{
			SentAndPosition lastone = SentAndPosition();
			lastone.Sentence = tt;
			lastone.StartPosition = last;
			lastone.Length = InputString.size()-last;
			returnVector.push_back(lastone);
		}	
	}
	return returnVector;
}  