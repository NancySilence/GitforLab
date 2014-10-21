#include <ctime>
#include <set>
#include <cmath>

#include "../include/GetMeta.h"
#include "../include/json/json.h"

using namespace std;
using namespace Json;

bool GetMetaResult(string sKeyWords, MetaResult &metaResult)
{
	CGetMeta getMeta;
	string sRsltMeta;
	if (!getMeta.WorkThread( sKeyWords, sRsltMeta))
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
			metaData.abstract = arrayMetaData[i]["abstract"].asString();
			metaData.engine = arrayMetaData[i]["engine"].asString();
		}
	}
	else
		return false;

	return true;
}

static bool Test()
{
	MetaResult metaResult;
	if (GetMetaResult("html", metaResult))
		cout<<metaResult.totalnum<<endl;
}

