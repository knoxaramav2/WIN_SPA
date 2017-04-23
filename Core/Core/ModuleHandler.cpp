#include "Modules.h"
#include "FileUtil.h"

ModuleManager::ModuleManager()
{
	
}

void ModuleManager::LoadModule()
{
	
}

void ModuleManager::LoadModuleFolder(string path)
{
	vector <string> files = UTIL::getFilesInFolder(path);
	printf("%d\r\n", files.size());
	for(string file : files)
	{
		//string extension = file.substr(file.find_last_of('.'), file.length());

		printf("%s\r\n", file.c_str());
	}

	Sleep(5000);
}