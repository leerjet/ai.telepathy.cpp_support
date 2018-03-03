#pragma once

#include "Support.h"

namespace tlsupp
{
	class Exception
	{
	public:
		Exception();
		Exception(std::string Message);
		Exception(std::string strName, std::string strMessage);
		~Exception();

		std::string Message;
		std::string Name;
	};
}

