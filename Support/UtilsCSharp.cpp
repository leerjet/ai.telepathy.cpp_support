/**********************************************************************
* Copyright 2018 Telepathy Labs
*
* File: UtilsCSharp.cpp
*
* Description: Static support routines for TL C++ programs, with
*	ability to be called by C# programs. These routines will call
*	our C++ Utils routines, but handle the movement of arguments
*	and parameters as necessary to use with C#
*
* Author: Lee Rautenberg
*
***********************************************************************/

#ifdef CSharp

#include "UtilsCSharp.h"
#include "Support.h"
#include <memory>

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

void __cdecl DateNowUtc(char *strDate, int nLen)
{
	if (nLen < 16)
	{
		return;
	}
	string strDateNow = tlsupp::DateNowUtc();
	memset(strDate, 0, nLen);
	memcpy(strDate, (void *)&strDateNow[0], 14);
}

/**********************************************************************
*
* Method: DateToString
*
* Purpose: Returns formatted local date/time as YYYYMMDDHHMMSS
*
* Parameters:
*	none
*
* Remarks: starts with current local time
*
***********************************************************************/

void __cdecl DateToString(char *strDate, int nLen)
{
	if (nLen < 16)
	{
		return;
	}
	time_t timeNow = time(NULL);
	string strDateNow = tlsupp::DateToString(&timeNow);
	memset(strDate, 0, nLen);
	memcpy(strDate, (void *)&strDateNow[0], 14);
}

/**********************************************************************
*
* Method: DateToStringUtc
*
* Purpose: Returns formatted date/time in UTC as YYYYMMDDHHMMSS
*
* Parameters:
*	none
*
* Remarks: starts with current time
*
***********************************************************************/

void __cdecl DateToStringUtc(char *strDate, int nLen)
{
	if (nLen < 16)
	{
		return;
	}
	time_t timeNow = time(NULL);
	string strDateNow = tlsupp::DateToStringUtc(&timeNow);
	memset(strDate, 0, nLen);
	memcpy(strDate, (void *)&strDateNow[0], 14);
}

/**********************************************************************
*
* Method: JsonEscapeString
*
* Purpose: replace reserved JSON characters in a string with ESCaped characters
*
* Parameters:
*	Buffer with JSON string
*	Length of buffer
*
***********************************************************************/

void __cdecl JsonEscapeString(char *strJson, int nLen)
{
	string strEscJson = tlsupp::JsonEscapeString(strJson);
	memset(strJson, 0, nLen);
	memcpy(strJson, (void *)strEscJson.c_str(), nLen);
}

/**********************************************************************
*
* Method: StepThroughTests
*
* Purpose: Tests that need to be stepped through to check workings
*
* Parameters:
*	str - str buffer
*	nLen - length of buffer passed
*
***********************************************************************/

void __cdecl StepThroughTests(char *str, int nLen)
{
	bool fWorked = true;
	tlsupp::StringBuilder sb = tlsupp::StringBuilder();

	tlsupp::StringBuilder sbTemp = tlsupp::StringBuilder("abQcdab");
	sbTemp.DeleteCharAt(2);
	fWorked = sbTemp.ToString() == string("abcdab");
	sb.Append(string("StringBuilder::DeleteCharAt "));
	if (fWorked)
	{
		sb.Append(string("worked\r\n"));
	}
	else
	{
		sb.Append(string("failed\r\n"));
	}

	char *caBuf = new char[100];
	sbTemp.GetChars(1, 3, caBuf, 1);
	fWorked = ((caBuf[1] == 'b') && (caBuf[2] == 'c'));
	sb.Append(string("StringBuilder::GetChars "));
	if (fWorked)
	{
		sb.Append(string("worked\r\n"));
	}
	else
	{
		sb.Append(string("failed\r\n"));
	}

	fWorked = (2 == sbTemp.IndexOf(string("c")));
	sb.Append(string("StringBuilder::IndexOf-Str Found "));
	if (fWorked)
	{
		sb.Append(string("worked\r\n"));
	}
	else
	{
		sb.Append(string("failed\r\n"));
	}

	fWorked = ((sbTemp.IndexOf(string("cr")) < 0));
	sb.Append(string("StringBuilder::IndexOf-Str Not Found "));
	if (fWorked)
	{
		sb.Append(string("worked\r\n"));
	}
	else
	{
		sb.Append(string("failed\r\n"));
	}

	fWorked = (1 == sbTemp.IndexOf(string("b"), 1));
	sb.Append(string("StringBuilder::IndexOf-Str@pos Found "));
	if (fWorked)
	{
		sb.Append(string("worked\r\n"));
	}
	else
	{
		sb.Append(string("failed\r\n"));
	}

	fWorked = (4 == sbTemp.LastIndexOf(string("a")));
	sb.Append(string("StringBuilder::LastIndexOf-Str Found "));
	if (fWorked)
	{
		sb.Append(string("worked\r\n"));
	}
	else
	{
		sb.Append(string("failed\r\n"));
	}

	fWorked = ((sbTemp.LastIndexOf(string("ar")) < 0));
	sb.Append(string("StringBuilder::LastIndexOf-Str Not Found "));
	if (fWorked)
	{
		sb.Append(string("worked\r\n"));
	}
	else
	{
		sb.Append(string("failed\r\n"));
	}

	fWorked = (1 == sbTemp.LastIndexOf(string("b"), 4));
	sb.Append(string("StringBuilder::LastIndexOf-Str@pos Found "));
	if (fWorked)
	{
		sb.Append(string("worked\r\n"));
	}
	else
	{
		sb.Append(string("failed\r\n"));
	}

	fWorked = (6 == sbTemp.Length());
	sb.Append(string("StringBuilder::Length "));
	if (fWorked)
	{
		sb.Append(string("worked\r\n"));
	}
	else
	{
		sb.Append(string("failed\r\n"));
	}

	fWorked = (sbTemp.Reverse().ToString() == string("badcba"));
	sb.Append(string("StringBuilder::Reverse "));
	if (fWorked)
	{
		sb.Append(string("worked\r\n"));
	}
	else
	{
		sb.Append(string("failed\r\n"));
	}

	sbTemp.SetCharAt(0, 'Q');
	fWorked = (sbTemp.ToString() == string("Qadcba"));
	sb.Append(string("StringBuilder::SetCharAt "));
	if (fWorked)
	{
		sb.Append(string("worked\r\n"));
	}
	else
	{
		sb.Append(string("failed\r\n"));
	}

	fWorked = (sbTemp.Substr(3) == string("cba"));
	sb.Append(string("StringBuilder::Substr-Start "));
	if (fWorked)
	{
		sb.Append(string("worked\r\n"));
	}
	else
	{
		sb.Append(string("failed\r\n"));
	}

	fWorked = (sbTemp.Substr(2, 3) == string("dcb"));
	sb.Append(string("StringBuilder::Substr-Start&Len "));
	if (fWorked)
	{
		sb.Append(string("worked\r\n"));
	}
	else
	{
		sb.Append(string("failed\r\n"));
	}

	strcpy_s(str, nLen, sb.ToString().c_str());
	return;
}

/**********************************************************************
*
* Method: StringBuilder
*
* Purpose: Builds a string with multiple calls to append
*
* Parameters:
*	str - str buffer
*	nLen - length of buffer passed
*
***********************************************************************/

void __cdecl StringBuilder(char *str, int nLen)
{
	tlsupp::StringBuilder *sb = new tlsupp::StringBuilder(std::string("Start::Bool f="));
	sb->Append(false);
	sb->Append(string("; 'x'="));
	sb->Append('x');
	sb->Append(string("; int 123="));
	sb->Append(123);
	sb->Append(string("; double 1.2="));
	sb->Append((double)1.2L);
	sb->Append(string("; float 3.4="));
	sb->Append((float)3.4f);
	sb->Append(string("; long 91234567890="));
	sb->Append(91234567890ULL);
	sb->Append(string("\r\n"));

	tlsupp::StringBuilder sb2 = tlsupp::StringBuilder("123456789");
	tlsupp::StringBuilder sb3 = sb2.Insert(0, false);
	sb->Append("Insert bool(0): " + sb2.ToString() + "\r\n");
	sb2 = tlsupp::StringBuilder("123456789");
	sb3 = sb2.Insert(1, 'Q');
	sb->Append("Insert char Q (1): " + sb2.ToString() + "\r\n");
	sb2 = tlsupp::StringBuilder("123456789");
	sb3 = sb2.Insert(2, string("INSERTED"));
	sb->Append("Insert string (2): " + sb2.ToString() + "\r\n");
	sb2 = tlsupp::StringBuilder("123456789");
	sb3 = sb2.Insert(3, (double)1.2);
	sb->Append("Insert double (3): " + sb2.ToString() + "\r\n");
	sb2 = tlsupp::StringBuilder("123456789");
	sb3 = sb2.Insert(4, (float)3.14);
	sb->Append("Insert float (4): " + sb2.ToString() + "\r\n");
	sb2 = tlsupp::StringBuilder("123456789");
	sb3 = sb2.Insert(5, 625);
	sb->Append("Insert int (5): " + sb2.ToString() + "\r\n");
	sb3 = sb2.Insert(6, 91234567890ULL);
	sb->Append("Insert long (6): " + sb2.ToString() + "\r\n");

	strcpy_s(str, nLen, sb->ToString().c_str());
	return;
}

/**********************************************************************
*
* Method: StringReplace
*
* Purpose: Replaces every char in passed buffer with new character
*	ASCII string is assumed.
*
* Parameters:
*	str - ASCII string to be modified
*	nLen - length of buffer passed
*	cOrig - character to be replaced
*	cNew - replacing character
*
***********************************************************************/

void __cdecl StringReplace(char *str, int nLen, char *cOrig, char *cNew)
{
	string strC(str);
	strC = tlsupp::StringReplace(strC, *cOrig, *cNew);
	strcpy_s(str, nLen, strC.c_str());
	return;
}

/**********************************************************************
*
* Method: StringReplaceStr  (Cannot overload DllImport)
*
* Purpose: Replaces every occurrence of a string with another string.
*	ASCII string assumed
*
* Parameters:
*	str - ASCII string to be modified
*	nLen - length of buffer passed
*	strOrig - string to be replaced
*	strNew - replacing string
*
***********************************************************************/

void __cdecl StringReplaceStr(char *str, int nLen, char *strOrig, char *strNew)
{
	string strC(str);
	string strCOrig(strOrig);
	string strCNew(strNew);
	string strResult = tlsupp::StringReplace(strC, strCOrig, strCNew);
	strcpy_s(str, nLen, strResult.c_str());
	return;
}

/**********************************************************************
*
* Method: StringReplaceUtf8
*
* Purpose: Modifies passed string buffer replacing every occurrence of
*	one character with another.
*
* Parameters:
*	str - UTF8 string to be modified
*	nLen - length of buffer passed
*	cOrig - character to be replaced
*	cNew - replacing character
*
***********************************************************************/

void __cdecl StringReplaceUtf8(char *str, int nLen, char *cOrig, char *cNew)
{
	string strC(str);
	strC = tlsupp::StringReplaceUtf8(strC, *cOrig, *cNew);
	strcpy_s(str, nLen, strC.c_str());
	return;
}

#endif			// end of ifdef CSharp
