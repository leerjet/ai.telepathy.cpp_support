#pragma once
#ifdef CSharp

#include "stdafx.h"
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

extern "C"
{
	__declspec(dllexport) void __cdecl DateNowUtc(char *strdate, int nLen);
	__declspec(dllexport) void __cdecl DateToString(char *strdate, int nLen);
	__declspec(dllexport) void __cdecl DateToStringUtc(char *strdate, int nLen);
	__declspec(dllexport) void __cdecl JsonEscapeString(char *strJson, int nLen);
	__declspec(dllexport) void __cdecl StepThroughTests(char *strResult, int nLen);
	__declspec(dllexport) void __cdecl StringBuilder(char *strResult, int nLen);
	__declspec(dllexport) void __cdecl StringReplace(char *str, int nLen, char *cOrig, char *cNew);
	__declspec(dllexport) void __cdecl StringReplaceStr(char *str, int nLen, char *strOrig, char *strNew);
	__declspec(dllexport) void __cdecl StringReplaceUtf8(char *str, int nLen, char *cOrig, char *cNew);
}

#endif