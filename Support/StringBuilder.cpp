#include "Support.h"

namespace tlsupp
{
	StringBuilder::StringBuilder()
	{
		strSb = "";
	}

	StringBuilder::StringBuilder(string str)
	{
		strSb = str;
	}

	StringBuilder::StringBuilder(int nCapacity)
	{
		strSb = "";					// ignoring capacity...constructor for parallel to java/c#
	}

	StringBuilder::~StringBuilder()
	{
	};

	// Append various intrinsic types

	StringBuilder StringBuilder::Append(bool b)
	{
		strSb += (b ? "true" : "false");
		return(*this);
	}

	StringBuilder StringBuilder::Append(char c)
	{
		strSb += c;
		return(*this);
	}

	StringBuilder StringBuilder::Append(string str)
	{
		strSb += str;
		return(*this);
	}

	StringBuilder StringBuilder::Append(string str, int nIdx, int nLen)
	{
		strSb += str.substr(nIdx, nLen);
		return(*this);
	}

	StringBuilder StringBuilder::Append(double d)
	{
		string s = std::to_string(d);
		size_t pos = 0;
		char *cBuf = const_cast<char *>(s.c_str());
		if((pos = s.find('.', pos)) != std::string::npos)
		{
			// decimal point found...kill trailing zeros

			for (int i = s.length(); i >= 0; --i)
			{
				if (cBuf[i] == '.')
				{
					break;
				}
				if (cBuf[i] == '0')
				{
					cBuf[i] = 0;		// kill trailing 0
				}
			}
		}
		strSb += string(cBuf);
		return(*this);
	}

	StringBuilder StringBuilder::Append(float f)
	{
		string s = std::to_string(f);
		size_t pos = 0;
		char *cBuf = const_cast<char *>(s.c_str());
		if ((pos = s.find('.', pos)) != std::string::npos)
		{
			// decimal point found...kill trailing zeros

			for (int i = s.length(); i >= 0; --i)
			{
				if (cBuf[i] == '.')
				{
					break;
				}
				if (cBuf[i] == '0')
				{
					cBuf[i] = 0;		// kill trailing 0
				}
			}
		}
		strSb += string(cBuf);
		return(*this);
	}

	StringBuilder StringBuilder::Append(int n)
	{
		strSb += std::to_string(n);
		return(*this);
	}

	StringBuilder StringBuilder::Append(long l)
	{
		strSb += std::to_string(l);
		return(*this);
	}

	StringBuilder StringBuilder::Append(uint ui)
	{
		strSb += std::to_string(ui);
		return(*this);
	}

	StringBuilder StringBuilder::Append(ulong ul)
	{
		strSb += std::to_string(ul);
		return(*this);
	}

	StringBuilder StringBuilder::Append(ulonglong ull)
	{
		strSb += std::to_string(ull);
		return(*this);
	}

	int StringBuilder::Capacity()						// return capacity...will use current length
	{
		return(strSb.length());
	}

	char StringBuilder::CharAt(int nIdx)				// return character at specific index
	{
		if((uint)nIdx >= strSb.length())
		{
			throw(new Exception("IndexOutOfBoundsException", "Index passed is greater than end of StringBuilder"));
		}
		return(strSb[nIdx]);
	}

	StringBuilder StringBuilder::Clear()				// Empty String Builder
	{
		strSb.clear();
		return(*this);
	}

	StringBuilder StringBuilder::Delete(int nStartIdx, int nEndIdx)	// erase substring (start=inclusive; end=exclusive)
	{
		int nLen = nEndIdx - nStartIdx;
		if(((uint)nStartIdx >= strSb.length()) || ((uint)nEndIdx > (strSb.length() + 1)) || (nLen < 1))
		{
			throw(new Exception("IndexOutOfBoundsException", "Indices passed invalid for this StringBuilder"));
		}
		strSb.erase(nStartIdx, nLen);
		return(*this);
	}

	StringBuilder StringBuilder::DeleteCharAt(int nIdx)	// delete one character from StringBuilder
	{
		if ((uint)nIdx >= strSb.length())
		{
			throw(new Exception("IndexOutOfBoundsException", "Index passed invalid for this StringBuilder"));
		}
		strSb.erase(nIdx, 1);
		return(*this);
	}

	void StringBuilder::GetChars(int nStartIdx, int nEndIdx, char *caDest, int nIdxDest)
	{
		int nLen = nEndIdx - nStartIdx;
		if(((uint)nStartIdx >= strSb.length()) || ((uint)nEndIdx >= (strSb.length() + 1)))
		{
			throw(new Exception("IndexOutOfBoundsException", "Indices passed invalid for this StringBuilder"));
		}
		if (nLen > 0)
		{
			string strSubstr = strSb.substr(nStartIdx, nLen);
			memcpy(caDest + nIdxDest, strSubstr.c_str(), nLen);
		}
	}

	int StringBuilder::IndexOf(string strSearch)					// find 1st occurrence of string
	{
		return(strSb.find(strSearch));
	}

	int StringBuilder::IndexOf(string strSearch, int nStart)		// find first occurrence (after nStart - 1)
	{
		return(strSb.find(strSearch, nStart));
	}

	// Insert various intrinsic types

	StringBuilder StringBuilder::Insert(int nIdx, bool b)
	{
		if((uint)nIdx >= strSb.length())
		{
			throw(new Exception("IndexOutOfBoundsException", "Start position passed end of this StringBuilder"));
		}
		strSb.insert(nIdx, (b ? "true" : "false"));
		return(*this);
	}

	StringBuilder StringBuilder::Insert(int nIdx, char c)
	{
		if ((uint)nIdx >= strSb.length())
		{
			throw(new Exception("IndexOutOfBoundsException", "Start position passed end of this StringBuilder"));
		}
		strSb.insert(nIdx, 1, c);
		return(*this);
	}

	StringBuilder StringBuilder::Insert(int nIdx, string str)
	{
		if ((uint)nIdx >= strSb.length())
		{
			throw(new Exception("IndexOutOfBoundsException", "Start position passed end of this StringBuilder"));
		}
		strSb.insert(nIdx, str);
		return(*this);
	}

	StringBuilder StringBuilder::Insert(int nIdx, double d)
	{
		if ((uint)nIdx >= strSb.length())
		{
			throw(new Exception("IndexOutOfBoundsException", "Start position passed end of this StringBuilder"));
		}
		string s = std::to_string(d);
		size_t pos = 0;
		char *cBuf = const_cast<char *>(s.c_str());
		if ((pos = s.find('.', pos)) != std::string::npos)
		{
			// decimal point found...kill trailing zeros

			for (int i = s.length(); i >= 0; --i)
			{
				if (cBuf[i] == '.')
				{
					break;
				}
				if (cBuf[i] == '0')
				{
					cBuf[i] = 0;		// kill trailing 0
				}
			}
		}
		strSb.insert(nIdx, string(cBuf));
		return(*this);
	}

	StringBuilder StringBuilder::Insert(int nIdx, float f)
	{
		if ((uint)nIdx >= strSb.length())
		{
			throw(new Exception("IndexOutOfBoundsException", "Start position passed end of this StringBuilder"));
		}
		string s = std::to_string(f);
		size_t pos = 0;
		char *cBuf = const_cast<char *>(s.c_str());
		if ((pos = s.find('.', pos)) != std::string::npos)
		{
			// decimal point found...kill trailing zeros

			for (int i = s.length(); i >= 0; --i)
			{
				if (cBuf[i] == '.')
				{
					break;
				}
				if (cBuf[i] == '0')
				{
					cBuf[i] = 0;		// kill trailing 0
				}
			}
		}
		strSb.insert(nIdx, string(cBuf));
		return(*this);
	}

	StringBuilder StringBuilder::Insert(int nIdx, int n)
	{
		if ((uint)nIdx >= strSb.length())
		{
			throw(new Exception("IndexOutOfBoundsException", "Start position passed end of this StringBuilder"));
		}
		strSb.insert(nIdx, std::to_string(n));
		return(*this);
	}

	StringBuilder StringBuilder::Insert(int nIdx, long l)
	{
		if ((uint)nIdx >= strSb.length())
		{
			throw(new Exception("IndexOutOfBoundsException", "Start position passed end of this StringBuilder"));
		}
		strSb.insert(nIdx, std::to_string(l));
		return(*this);
	}

	StringBuilder StringBuilder::Insert(int nIdx, uint ui)
	{
		if ((uint)nIdx >= strSb.length())
		{
			throw(new Exception("IndexOutOfBoundsException", "Start position passed end of this StringBuilder"));
		}
		strSb.insert(nIdx, std::to_string(ui));
		return(*this);
	}

	StringBuilder StringBuilder::Insert(int nIdx, ulong ul)
	{
		if ((uint)nIdx >= strSb.length())
		{
			throw(new Exception("IndexOutOfBoundsException", "Start position passed end of this StringBuilder"));
		}
		strSb.insert(nIdx, std::to_string(ul));
		return(*this);
	}

	StringBuilder StringBuilder::Insert(int nIdx, ulonglong ull)
	{
		if ((uint)nIdx >= strSb.length())
		{
			throw(new Exception("IndexOutOfBoundsException", "Start position passed end of this StringBuilder"));
		}
		strSb.insert(nIdx, std::to_string(ull));
		return(*this);
	}

	int StringBuilder::LastIndexOf(string strSearch)				// find last occurrence of string
	{
		return(strSb.rfind(strSearch));
	}

	int StringBuilder::LastIndexOf(string strSearch, int nStart)	// find last occurrence (after nStart - 1)
	{
		return(strSb.rfind(strSearch, nStart));
	}

	int StringBuilder::Length()										// return length
	{
		return(strSb.length());
	}

	StringBuilder StringBuilder::Replace(int nStart, int nEnd, string strReplace)	// replace string withing 
	{
		if (((uint)nStart >= strSb.length()) || ((uint)nEnd >= (strSb.length() + 1)))
		{
			throw(new Exception("IndexOutOfBoundsException", "Indices passed invalid for this StringBuilder"));
		}
		strSb.replace((uint)nStart, (uint)(nEnd - nStart), strReplace);
		return(*this);
	}

	StringBuilder StringBuilder::Reverse()							// reverse string withing 
	{
		std::reverse(strSb.begin(), strSb.end());
		return(*this);
	}

	void StringBuilder::SetCharAt(int nIdx, char cNew)				// replace character at specific index
	{
		if ((uint)nIdx >= strSb.length())
		{
			throw(new Exception("IndexOutOfBoundsException", "Index passed is greater than end of StringBuilder"));
		}
		strSb.replace(nIdx, 1, 1, cNew);
	}

	string StringBuilder::Substr(int nIdx)							// substring from start index
	{
		if ((uint)nIdx >= strSb.length())
		{
			throw(new Exception("IndexOutOfBoundsException", "Index passed is greater than end of StringBuilder"));
		}
		return(strSb.substr(nIdx));
	}

	string StringBuilder::Substr(int nIdx, int nLen)				// substring from start index for length
	{
		if(((uint)nIdx >= strSb.length()) && ((uint)(nIdx + nLen) <= strSb.length()))
		{
			throw(new Exception("IndexOutOfBoundsException", "Index passed is greater than end of StringBuilder"));
		}
		return(strSb.substr(nIdx, nLen));
	}

	string StringBuilder::ToString()								// return copy of internal string
	{
		return(strSb);
	}

}


