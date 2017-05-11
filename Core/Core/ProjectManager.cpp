#include <windows.h>
#include <fstream>
#include <iostream>

#include "../SDK/CColor.h"

#include "ProjectManager.h"
#include "FileUtil.h"
#include "StringUtil.h"

const string projectPath = "projects\\";

ProjectHandle * ProjectManager::Current = NULL;

bool createProjectBase(string path)
{
	//generate folder structure
	if (!UTIL::createDirectory(path)) return false;



	return true;
}

ProjectManager::ProjectManager()
{
	Current = NULL;
}

ProjectHandle * ProjectManager::NewProject(string name)
{
	printc("Creating project " + name + "\r\n", CYAN);

	wstring path = UTIL::str2wstr(projectPath + name);
	if (CreateDirectory(path.c_str(), NULL) || 
		ERROR_ALREADY_EXISTS == GetLastError())
	{
		printc("Project " + projectPath + name + " already exists \
			or is unable to be accessed\r\n", RED);
		return NULL;
	}

	//generate base project files



	//load and assign handle

	if (!createProjectBase(projectPath + name))
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
