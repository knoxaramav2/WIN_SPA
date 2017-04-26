#pragma once
#ifndef FILEUTIL
#define FILEUTIL

#include <string>
#include <vector>
#include <windows.h>

using namespace std;

namespace UTIL
{
	vector <string> getFilesInFolder(string path);

	string getExtention(string file);

	bool fileExists(string file);

	HANDLE createFile(string file);
	bool createDirectory(string file);
}


#endif