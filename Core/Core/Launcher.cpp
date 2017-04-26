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

int parseCmd(int argc, char ** argv)
{
	int ret = 0;

	//post cmd operations
	bool newProject = false;
	bool loadProject = false;

	//buffers
	string projName;

	for(int i = 1; i < argc; ++i)
	{
		string arg = string(argv[i]);

		if (arg[0]!='-')
		{
			printc("Invalid opton ["+string(argv[i])+"]\r\n", FOREGROUND_RED);
			ret |= 1;
			continue;
		}

		if (argv[i][1]=='-')
		{
			if (arg == "--max_node" && isInteger(argv[++i]))
			{
				config.maxNodes = atoi(argv[i]);
			} else if (arg == "--max_threads" && isInteger(argv[++i]))
			{
				config.maxThread = atoi(argv[i]);
			}
			else if (arg == "--new_proj")
			{
				if (i < argc)
				{
					newProject = true;
					projName = argv[++i];
				}
				else
				{
					printc("Requires a project name\r\n", RED);
					ret |= -1;
				}
			}
			else if (arg == "--load_proj")
			{
				if (i < argc)
				{
					loadProject = true;
					projName = argv[++i];
				}
				else
				{
					printc("Requires a project name\r\n", RED);
					ret |= -1;
				}
			}
			else
			{
				printc("Unrecognized option " + string(argv[i]) + "\r\n", RED);
				ret |= 1;
			}
		}else
		{
			for(int j = 1; j < strlen(argv[i]); ++j)
			{
				switch(argv[i][j])
				{
				case 'd': config.debug = true; break;
				case 'v': config.verbose = true; break;
				case 'V': break;
				default:
					printc("Unrecognized option -" + string(argv[i][j], 1) + "\r\n", FOREGROUND_RED);
					ret |= 1;
				}
			}
		}
	}
	
	//verify post cmd operations
	if (newProject && loadProject)
	{
		printc("Cannot load and create a project simultaneously\r\n", RED);
		return ret |= 1;
	}

	//launch post cmd operations
	if (newProject) ProjectManager::NewProject(projName);
	if (loadProject) ProjectManager::LoadProject(projName);

	return ret;
}

int main(int argc, char ** argv)
{
	ModuleManager modManager;

	verifyDirectories();

	int rcode = parseCmd(argc, argv);
	if (rcode != 0) return rcode;

	//detect and load modules
	modManager.LoadModuleFolder("E:\\Dev\\C++\\WIN_SPA\\Core\\Core\\*");

	//load network state


	//execute

	//save state

	return 0;
}