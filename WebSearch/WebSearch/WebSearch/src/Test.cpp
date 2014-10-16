#include <ctime>
#include <set>
#include <cmath>


#include "GetMeta.h"
#include "json/json.h"

using namespace std;
using namespace Json;


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

bool GetMetaResult(string sKeyWords, MetaResult &metaResult, bool bReal = false)
{
	CGetMeta getMeta;
	string sRsltMeta;
	if (!getMeta.WorkThread( sKeyWords, sRsltMeta, bReal))
		return false;

	Reader reader;
	Value root;
	if (reader.parse(sRsltMeta, root))
	{
		metaResult.totalnum = root["totalnum"].asInt();
		const Value arrayMetaData = root["metadata"];
		int num = arrayMetaData.size();
		for (int i = 0; i < num; ++i)
		{
			MetaData metaData;
			metaData.title = arrayMetaData[i]["title"].asString();
			metaData.url = arrayMetaData[i]["url"].asString();
			metaData.site = arrayMetaData[i]["site"].asString();
			metaData.pubtime = arrayMetaData[i]["pubtime"].asString();
			cout<<metaData.pubtime<<endl;
			metaData.abstract = arrayMetaData[i]["abstract"].asString();
			metaData.engine = arrayMetaData[i]["engine"].asString();
		}
	}
	else
		return false;

	return true;
}

bool Test()
{
	MetaResult metaResult;
	if (GetMetaResult("ÖÐ¹ú", metaResult))
		cout<<metaResult.totalnum<<endl;
}

int main()
{
	Test();
}
