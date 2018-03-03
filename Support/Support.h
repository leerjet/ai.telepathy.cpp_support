#pragma once

//#include "stdafx.h"

using namespace std;

#include <algorithm>
#include <ctime>
#include <iostream>
#include <memory>
#include <string>

#include "Defines.h"
#include "Exception.h"
#include "StringBuilder.h"


// Routines below are not within any class - essentially namespace methods

namespace tlsupp
{
	string DateNowUtc();
	string DateToString(time_t *rawtime);
	string DateToStringUtc(time_t *rawtime);
	string JsonEscapeString(string strSource);
	string StringReplace(string str, char cOrig, char cNew);
	string StringReplace(string str, string strOrig, string strNew);
	string StringReplaceUtf8(string str, char cOrig, char cNew);
}

