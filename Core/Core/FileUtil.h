#pragma once
#ifndef FILEUTIL
#define FILEUTIL

#include <vector>
#include <windows.h>

using namespace std;

namespace UTIL
{
	vector <string> getFilesInFolder(string path);

	string getExtention(string file);

	bool fileExists(string file);
	bool directoryExists(string path);

	HANDLE createFile(string file);
	bool createDirectory(string file);
}


#endif