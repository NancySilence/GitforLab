#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>


using namespace std;


std::vector< std::string >  split(std::string& InputString)  
{  
	string SrcFile;
	SrcFile = "src/splitPunct.txt";
	ifstream infile(SrcFile.c_str());
	vector<string> punct;
	punct.clear();
	vector<int> indexVector;
	vector<string> returnVector;

	
	while(!infile.eof() ) 
	{
		string temp;
		getline(infile,temp);
		punct.push_back(temp); 
	}

	for(vector<string>::size_type ix = 1;ix<punct.size();ix++)
	{
		findIndex(InputString,punct[ix],indexVector);
	}

	sort(indexVector.begin(),indexVector.end());

	size_t last = 0;
	size_t indexnow;
	for(vector<int>::size_type ix = 1;ix<indexVector.size();ix++)
	{
		indexnow = indexVector[ix];
		returnVector.push_back(InputString.substr(last,indexnow-last));
		last = indexnow+1;
	}

	if(indexVector[indexVector.size()]<InputString.size())
	{
		returnVector.push_back(InputString.substr(last,InputString.size()-last));
	}
	return returnVector;
}  


void findIndex(string & str,string &source,vector<int>& indexVector)
{
	string temp,p;
	int lens = source.length();

	size_t last = 0;
	size_t index=str.find_first_of(source,0);  
    while (index!=std::string::npos)  
    {  
		indexVector.push_back(index);  
        last=index+1;  
        index=str.find_first_of(source,last);  
    }  

}

/*
void replace(char *str, char *s, char *t)
{
    char temp[256], *p;
    int lens = strlen(s),
        lent = strlen(t);
        
    
	p = strstr(str, s);     //p指向str中查找到的s
    while(p!=NULL)
	{
		strcpy(temp, p+lens);   //字符串分三个部分，把最后一个部分先存到temp里
		strcpy(p, t);           //把t接到第二部分
		strcpy(p+lent, temp);   //还原第三部分
		p = strstr(str, s);     //p指向str中查找到的s
	}
}
*/

