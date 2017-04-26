#include <windows.h>
#include <fstream>

#include "../SDK/CColor.h"

#include "ProjectManager.h"
#include "FileUtil.h"

const string projectPath = "projects\\";

ProjectManager::ProjectManager()
{
	Current = NULL;
}

ProjectHandle * ProjectManager::NewProject(string name)
{
	printc("Creating project " + name + "\r\n", YELLOW);

	if (UTIL::fileExists(name))
	{
		printc("Project already exists\r\n", RED);
		return NULL;
	}

	if (!UTIL::createDirectory(projectPath + name))
	{
		printc("Project directory could not be made\r\n", RED);
		return NULL;
	}

	ofstream writer(projectPath + name + ".proj");

	//create base file

	writer.close();

	Current = new ProjectHandle();

	return Current;
}

ProjectHandle * ProjectManager::LoadProject(string name)
{
	

	return Current;
}
