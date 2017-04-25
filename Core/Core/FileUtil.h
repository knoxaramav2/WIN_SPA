#pragma once
#ifndef FILEUTIL
#define FILEUTIL

#include <string>
#include <vector>

using namespace std;

namespace UTIL
{
	vector <string> getFilesInFolder(string path);

	string getExtention(string file);
}


#endif