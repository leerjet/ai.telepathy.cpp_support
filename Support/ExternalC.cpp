// ExternalC.cpp : Defines the exported functions for the DLL application.
//

#include "Support.h"
using namespace std;

void __cdecl QuoteAString(char *strSource, int nLen)
{
	memset(strSource, 0, 10);
	memcpy(strSource, "abqcwd", 3);
// 	if (strSource[0] == 'a')
// 	{
// 		return 2ll;
// 	}
// 	return 3ll;
}
