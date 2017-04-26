#include "FileUtil.h"
#include "StringUtil.h"

vector <string> UTIL::getFilesInFolder(string path)
{
	PVOID oldpvoid = NULL;

	vector <string> list;
	wstring lstr = str2wstr(path);

	WIN32_FIND_DATA data;
	HANDLE hFind = FindFirstFile(lstr.c_str(), &data);

	if (hFind == INVALID_HANDLE_VALUE)
		return list;

	Wow64DisableWow64FsRedirection(&oldpvoid);
	do {
		wstring ws(data.cFileName);
		string str(ws.begin(), ws.end());
		list.push_back(str);
	} while (FindNextFile(hFind, &data));
	FindClose(hFind);
	Wow64RevertWow64FsRedirection(oldpvoid);

	return list;
}

string UTIL::getExtention(string file)
{
	size_t pos = file.find_first_of('.');

	if (pos == string::npos)
		return "";

	return file.substr(pos, file.length()-1);
}

bool UTIL::fileExists(string file)
{
	struct stat buffer;
	return (stat(file.c_str(), &buffer) == 0);
}


/*
 *References
 *https://stackoverflow.com/questions/12774207/fastest-way-to-check-if-a-file-exist-using-standard-c-c11-c
 */
HANDLE UTIL::createFile(string file)
{
	return NULL;
}

bool UTIL::createDirectory(string file)
{
	return !CreateDirectory(
		str2wstr(file).c_str(),
		NULL);
}
