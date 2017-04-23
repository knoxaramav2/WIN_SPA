#include "FileUtil.h"

#include <windows.h>
#include "StringUtil.h"
#include <iostream>

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
