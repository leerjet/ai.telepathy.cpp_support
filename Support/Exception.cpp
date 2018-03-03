#include "Support.h"

namespace tlsupp
{
	Exception::Exception()
	{
		Message = "";
		Name = "Exception";
	}
	Exception::Exception(std::string Message)
	{
		Message = "";
	}

	Exception::Exception(std::string strName, std::string strMessage)
	{
		Name = strName;
		Message = strMessage;
	}

	Exception::~Exception()
	{
	}
}
