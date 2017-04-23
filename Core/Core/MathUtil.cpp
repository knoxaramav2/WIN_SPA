#include "MathUtil.h"

bool UTIL::isInteger(std::string s)
{
	for (char c : s)
	{
		if (c<'0' || c>'9')
		{
			return false;
		}
	}

	return true;
}

bool UTIL::isDecimal(std::string s)
{
	bool isDecimal = false;

	for (char c : s)
	{
		if ((c<'0' || c>'9') && c!='.')
		{
			return false;
		}

		isDecimal = c == '.' ? true : isDecimal;
	}

	return isDecimal;
}

bool UTIL::isNumeric(std::string s)
{
	for (char c : s)
	{
		if ((c<'0' || c>'9') && c != '.')
		{
			return false;
		}
	}

	return true;
}

unsigned long UTIL::fnv1a(std::string s)
{
	return 0;
}
