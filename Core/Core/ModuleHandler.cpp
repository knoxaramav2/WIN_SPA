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
		string extension = UTIL::getExtention(file);
		if (extension != ".dll")
			continue;

		//TODO
		//load module
	}

	Sleep(5000);
}