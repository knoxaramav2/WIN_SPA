#pragma once
#ifndef STRINGUTIL
#define STRINGUTIL
#include <windows.h>
#include <string>
#include <vector>

namespace UTIL
{
	std::wstring str2wstr(std::string s);
	LPCWSTR str2lpcwstr(std::string s);//Doesn't work
	std::string lpcwstr2str(LPCWSTR s);

	std::vector<std::string> splitString(char *, char);
}

#endif