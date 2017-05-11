#include "StringUtil.h"
#include <iostream>

std::wstring UTIL::str2wstr(std::string s)
{
	int slength = (int)s.length() + 1;
	int length = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
	wchar_t* buf = new wchar_t[length];
	MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, length);
	std::wstring r(buf);
	delete[] buf;
	std::wcout << L"------------------" << r.c_str() << std::endl;
	return r;
}

LPCWSTR UTIL::str2lpcwstr(std::string s)
{
	int slength = (int)s.length() + 1;
	int length = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
	wchar_t* buf = new wchar_t[length];
	MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, length);
	std::wstring r(buf);
	delete[] buf;
	LPCWSTR ret = r.c_str();
	std::wcout << L"------------------" << ret << std::endl;
	
	return ret;
}

std::string UTIL::lpcwstr2str(LPCWSTR s)
{
	int len = wcslen(s);
	char * buf = new char[len+1];
	int length = WideCharToMultiByte(CP_ACP, 0, s, len + 1, buf, len+1, NULL, NULL);

	return buf;
}

std::vector<std::string> UTIL::splitString(char * raw, char split)
{
	std::vector<std::string> ret;
	
	char * s = raw;
	char * e = raw;
	char * x = raw + strlen(raw);

	while(*e!=NULL)
	{
		if (*e == split || (e+1) == x)
		{
			ret.push_back(std::string(s, (e+1)==x? e+1: e ));
			s = e + 1;
		}

		++e;
	};

	return ret;
}
