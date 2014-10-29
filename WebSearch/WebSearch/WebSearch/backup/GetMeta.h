#ifndef __GETMETA_H__
#define __GETMETA_H__
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class CGetMeta{
public:
	CGetMeta(){}
	~CGetMeta(){}
public:

	bool WorkThread(string sKeyWords, string& sRsltMeta, bool bReal = false);
};

struct MetaData
{
	string title;
	string url;
	string site;
	string pubtime;
	string abstract;
	string engine;
};

struct MetaResult
{
	int totalnum;
	vector<MetaData> metaDatas;
};

bool GetMetaResult(string sKeyWords, MetaResult &metaResult);

#endif
