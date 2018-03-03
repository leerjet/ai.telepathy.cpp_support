/**********************************************************************
* Copyright 2018 Telepathy Labs
*
* File: Utils.cpp
*
* Description: Static support routines for TL C++ programs
*
* Author: Lee Rautenberg
*
***********************************************************************/

#include "Support.h"
#include <memory>
#include <string>

/**********************************************************************
*
* Method: DateNowUtc
*
* Purpose: Returns formatted date/time in UTC as YYYYMMDDHHMMSS
*
* Parameters:
*	none
*
* Remarks:
*
***********************************************************************/
class Test
{
public:
	int Number;
	int AnotherNumber;

	Test()
	{
		Number = 3;
		AnotherNumber = 5;
	}

	Test(int x)
	{
		Number = 4;
		AnotherNumber = x;
	}

	~Test()
	{
		int j = 3;
	}

	int Multiply()
	{
		return(Number * AnotherNumber);
	}

	std::string returnTest()
	{
		std::string x = "String";
		return(x);
	}
};
void __cdecl DateNowUtc(char *strDate, int nLen)
{
	if (nLen < 16)
	{
		return;
	}
	Test q = Test(3);
	int yy = q.Multiply();
 	Test *x = new Test(6);
 	int y = x -> Multiply();
	unique_ptr<Test> z(new Test(2));
	int yyy = z->Multiply();
	std:string str = x->returnTest();

	memset(strDate, 0, nLen);
	memcpy(strDate, "20010101000000", 14);
}

