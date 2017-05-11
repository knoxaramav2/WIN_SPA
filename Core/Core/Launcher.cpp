#define WIN32_LEAN_AND_MEAN

#include <stdio.h>
#include <windows.h>

#include "../SDK/global_config.h"
#include "../SDK/CColor.h"

#include "MathUtil.h"
#include "StringUtil.h"
#include "Modules.h"
#include "ProjectManager.h"

G_Config config;

using namespace UTIL;

void verifyDirectories()
{
	LPCWSTR dirs [] = {
		L"modules",
		L"output",
		L"projects",
		L"log"
	};

	for (LPCWSTR dir : dirs)
	{
		string sdir = lpcwstr2str(dir);
		DWORD ftyp = GetFileAttributesA(sdir.c_str());
		if (ftyp & FILE_ATTRIBUTE_DIRECTORY && ftyp != INVALID_FILE_ATTRIBUTES) continue;

		printf("Creating directory %s\r\n", sdir.c_str());

		if (CreateDirectory(dir, NULL) == 0)
		{
			printf("! Failed to create directory -> %s\r\n", sdir.c_str());
		}
	}
}

int parseCmd(int argc, char ** argv, G_Config config);

int main(int argc, char ** argv)
{
	ModuleManager modManager;

	verifyDirectories();

	int rcode = parseCmd(argc, argv, config);
	if (rcode != 0) return rcode;

	//detect and load modules
	modManager.LoadModuleFolder("E:\\Dev\\C++\\WIN_SPA\\Core\\Core\\*");

	//execute

	//save state

	return 0;
}