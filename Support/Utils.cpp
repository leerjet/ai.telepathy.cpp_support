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

namespace tlsupp
{

	const char *fmtDate = "%Y%m%d%H%M%S";

	/**********************************************************************
	*
	* Method: DateNowUtc
	*
	* Purpose: Returns formatted date/time in UTC as YYYYMMDDHHMMSS
	*
	* Parameters:
	*	none
	*
	* Return: Current UTC time a YYYYMMDDHHMMSS
	*
	***********************************************************************/

	string DateNowUtc()
	{
		time_t rawUtcTime;
		struct tm tmInfo;
		char buf[80];

		rawUtcTime = time(NULL);						// get current time (secs past 1/1/1970)
		gmtime_s(&tmInfo, &rawUtcTime);					// convert time to time structure
		strftime(buf, sizeof(buf), fmtDate, &tmInfo);	// format the date/time
		string str(buf);								// create string to return
		return(str);
	}

	/**********************************************************************
	*
	* Method: DateToString
	*
	* Purpose: Returns formatted local date/time of passed time
	*
	* Parameters:
	*	none
	*
	* Return: string UTC time a YYYYMMDDHHMMSS based on passed time value
	*
	***********************************************************************/

	string DateToString(time_t *rawtime)
	{
		struct tm tmInfo;
		char buf[80];

		localtime_s(&tmInfo, rawtime);					// convert time to time structure
		strftime(buf, sizeof(buf), fmtDate, &tmInfo);	// format the date/time
		string str(buf);								// create string to return
		return(str);
	}

	/**********************************************************************
	*
	* Method: DateToStringUtc
	*
	* Purpose: Returns formatted date/time of passed time
	*
	* Parameters:
	*	none
	*
	* Return: string UTC time a YYYYMMDDHHMMSS based on passed time value
	*
	***********************************************************************/

	string DateToStringUtc(time_t *rawtime)
	{
		struct tm tmInfo;
		char buf[80];

		gmtime_s(&tmInfo, rawtime);						// convert time to time structure
		strftime(buf, sizeof(buf), fmtDate, &tmInfo);	// format the date/time
		string str(buf);								// create string to return
		return(str);
	}

	/**********************************************************************
	*
	* Method: JsonEscapeString
	*
	* Purpose: Replace reserved JSON characters in a string with ESCaped characters
	*
	* Parameters:
	*	strSource - presumed JSON string to Escape
	*
	* Return: ESCaped JSON string
	*
	***********************************************************************/

	string JsonEscapeString(string strSource)
	{
		string strResult = StringReplace(strSource, "\t", "\\t");
		strResult = StringReplace(strResult, "\n", "\\n");
		strResult =  StringReplace(strResult, "\\", "\\\\");
		return strResult;
	}

	/**********************************************************************
	*
	* Method: StringReplace
	*
	* Purpose: Modifies string passed by reference by replacing every
	*	occurrence of one character with another.
	*	Assumes the string is ASCII.
	*
	* Parameters:
	*	str - c++ ASCII string reference
	*	cOrig - ASCII character to replace
	*	cNew - ASCII character replacing cOrig
	*
	* Return: modified string
	*
	* Remarks: Does nothing if either character is NULL
	*
	***********************************************************************/

	string StringReplace(string str, char cOrig, char cNew)
	{
		std::replace(str.begin(), str.end(), cOrig, cNew);
		return(str);
	}

	/**********************************************************************
	*
	* Method: StringReplace
	*
	* Purpose: Modifies string passed by reference by replacing every
	*	occurrence of one string with another.
	*	Assumes the string is ASCII.
	*
	* Parameters:
	*	str - c++ ASCII string reference
	*	strOrig - ASCII string to replace
	*	strNew - ASCII string replacing strOrig
	*
	* Return: result as a new string
	*
	***********************************************************************/

	string StringReplace(string str, string strOrig, string strNew)
	{
		size_t pos = 0;
		while ((pos = str.find(strOrig, pos)) != std::string::npos)
		{
			str.replace(pos, strOrig.length(), strNew);
			pos += strNew.length();
		}
		return str;
	}

	/**********************************************************************
	*
	* Method: StringReplaceUtf8
	*
	* Purpose: Modifies string passed by reference by replacing every
	*	occurrence of one character with another.
	*	Assumes the string is in UTF8 format.
	*
	* Parameters:
	*	str - c++ UTF8 string reference
	*	cOrig - ASCII character to replace
	*	cNew - ASCII character replacing cOrig
	*
	* Return: source string as a convenience
	*
	* Remarks: Does nothing if either character is NULL
	*	See https://en.wikipedia.org/wiki/UTF-8 for details about UTF-8
	*
	***********************************************************************/

	string StringReplaceUtf8(string str, char cOrig, char cNew)
	{
		char c;									// reusable char
		if ((NULL != cOrig) && (NULL != cNew))
		{
			for (unsigned int i = 0; i < str.length(); ++i)
			{
				c = str[i];
				if ((c & 0x80) == 0)			// ASCII character?
				{
					if (c == cOrig)
					{
						str[i] = cNew;
					}
				}
				else if ((c & 0xb0) == 0xc0)	// 2 byte Unicode character?
				{
					++i;					// skip an extra byte
				}
				else if ((c & 0xf0) == 0xb0)	// 3 byte Unicode character?
				{
					i += 2;					// skip 2 bytes
				}
				else if ((c & 0xf8) == 0xf0)	// 4 byte Unicode character?
				{
					i += 3;					// skip 3 bytes
				}
			}
		}
		return(str);
	}

}		// end of namespace tlsupp

