#include <iostream>
#include <string>
#include "include/SimHashAPI.h"

using namespace std;

int main(void)
{
	int returnResult;
	SH_H ** handle;
	string  testSim= "Start from something new";

	char ConfigFile[40] = "config/simhash.config.xml";
	uint64_t HashResult;

	returnResult = SH_Init(ConfigFile,  handle);
	cout<<"Init Result:"<<returnResult<<endl;

	returnResult = SH_Get(handle, testSim, HashResult);

	cout<<"Get Result:"<<returnResult<<endl;

	cout<<"SimHash Result:"<<HashResult<<endl;

	returnResult = SH_Exit(handle);
	cout<<"Exit Result:"<<returnResult<<endl;

	cin>>returnResult;
	return 0;
}
