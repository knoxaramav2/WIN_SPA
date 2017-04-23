#pragma once
#ifndef MATHUTIL
#define MATHUTIL
#include <string>

namespace UTIL
{
	//string analysis
	bool isInteger(std::string s);
	bool isDecimal(std::string s);
	bool isNumeric(std::string s);

	//hashes
	unsigned long fnv1a(std::string s);
}



#endif