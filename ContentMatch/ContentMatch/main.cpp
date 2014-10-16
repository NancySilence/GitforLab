#include <iostream>
#include <string>
#include "../include/SimHashAPI.h"

using namespace std;

int main(void)
{
//for each string.
	char ConfigFile[40] = "config/simhash.config.xml";
	uint64_t HashResult;
	int returnResult;
	SH_H * handle;

	//Iteration Start
	string  testSim= "Start from something new";
	
	returnResult = SH_Init(ConfigFile,  &handle);
	cout<<"InitResult:"<<returnResult<<endl;

	returnResult = SH_Get(handle, testSim, HashResult);
	cout<<"GetResult:"<<returnResult<<endl;
	cout<<endl<<"HashResult:!!"<<HashResult<<endl;
	returnResult = SH_Exit(handle);

	cout<<"ExitResult:"<<returnResult<<endl;
	return 0;
}
