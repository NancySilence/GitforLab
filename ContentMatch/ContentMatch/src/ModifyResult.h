#ifndef _MODIFY_RESULT_H_
#define _MODIFY_RESULT_H_


#include <iostream>
#include"ArticleAnalyze.h"
using namespace std;




class ModifyResult
{
public:
    ModifyResult(void)
	:type(-1),IndexA(-1),IndexB(-1)
    {
	}

    virtual ~ModifyResult(void)
    {
	}

public:
	//type: 0 B add;  1 A delete ; 2 A modified to B
    int type;
	int IndexA;
	int IndexB;
	string SentenceA;
	string SentenceB;

};

#endif