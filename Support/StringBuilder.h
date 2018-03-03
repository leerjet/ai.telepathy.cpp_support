#pragma once

#include "Support.h"

namespace tlsupp
{
	class StringBuilder
	{
	public:
			StringBuilder();
			StringBuilder(string str);
			StringBuilder(int nCapacity);
			~StringBuilder();

			StringBuilder Append(bool b);
			StringBuilder Append(char c);
			StringBuilder Append(string str);
			StringBuilder Append(string str, int nIdx, int nLen);
			StringBuilder Append(double d);
			StringBuilder Append(float f);
			StringBuilder Append(int b);
			StringBuilder Append(long b);
			StringBuilder Append(uint ui);
			StringBuilder Append(ulong ul);
			StringBuilder Append(ulonglong ull);

			int Capacity();
			char CharAt(int nIdx);
			StringBuilder Clear();
			StringBuilder Delete(int nStartIdx, int nEndIdx);
			StringBuilder DeleteCharAt(int nIdx);
			void GetChars(int nStartIdx, int nEndIdx, char *caDest, int nIdxDest);
			int IndexOf(string strSearch);
			int IndexOf(string strSearch, int nStart);
			StringBuilder Insert(int nIdx, bool b);
			StringBuilder Insert(int nIdx, char c);
			StringBuilder Insert(int nIdx, string str);
			StringBuilder Insert(int nIdx, double d);
			StringBuilder Insert(int nIdx, float f);
			StringBuilder Insert(int nIdx, int b);
			StringBuilder Insert(int nIdx, long b);
			StringBuilder Insert(int nIdx, uint ui);
			StringBuilder Insert(int nIdx, ulong ul);
			StringBuilder Insert(int nIdx, ulonglong ull);
			int LastIndexOf(string strSearch);
			int LastIndexOf(string strSearch, int nStart);
			int Length();
			StringBuilder Replace(int nStart, int nEnd, string strReplace);
			StringBuilder Reverse();
			void SetCharAt(int nIdx, char cNew);
			string Substr(int nIdx);
			string Substr(int nIdx, int nLen);
			string ToString();
			

	private:
		std::string strSb;
	};
}

