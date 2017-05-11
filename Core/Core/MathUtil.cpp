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

unsigned long UTIL::fnv1a(std::string str)
{
	// ReSharper disable once CppJoinDeclarationAndAssignment
	long long unsigned hash;

	#if _WIN64
		//printf("64 bit\n");
		hash = 14695981039346656037ULL;//FNV offset
	#else
		//printf("32 bit\n");
	// ReSharper disable once CppJoinDeclarationAndAssignment
		hash = 2166136261;
	#endif

		//64 prime 0xb3
		//32 prime 0x93

		for (size_t x = 0; x < str.length(); ++x)
		{
			hash ^= str[x];
	#if _WIN64==64
			hash *= 0xb3;
	#else
			hash *= 0x93;
	#endif
	}
	return hash;
}

unsigned long UTIL::fnv1a32(std::string str)
{
	long long unsigned hash = 2166136261;

	for (size_t x = 0; x < str.length(); ++x)
	{
		hash ^= str[x];
		hash *= 0x93;
	}
	return hash;
}
