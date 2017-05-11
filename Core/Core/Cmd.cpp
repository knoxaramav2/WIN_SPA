#include <stdio.h>
#include <windows.h>

#include "../SDK/global_config.h"
#include "../SDK/CColor.h"
#include "MathUtil.h"
#include "ProjectManager.h"
#include "StringUtil.h"

using namespace UTIL;
using namespace std;

int errors = 0;

//Utils
void postVersion()
{
	
}

//Cmd
enum ArgType
{
	_numeric,
	_nonNumeric,
	_integer,
	_path,
};

void postCmdErr(string msg)
{
	++errors;
	printc(msg, RED);
	printf("\r\n");
}

void postCmdWrn(string msg)
{
	printc(msg, YELLOW);
	printf("\r\n");
}

bool validateArgument(string s, ArgType type)
{
	if (type == _numeric)
	{
		return isNumeric(s);
	}
	else if (type == _nonNumeric)
	{
		return !isNumeric(s);
	} else if (type == _integer)
	{
		return isInteger(s);
	} else if (type == _path)
	{
		return true;
	}

	return false;
}

bool validateArguments(vector<string> args, ArgType type)
{
	for(string s : args)
	{
		if (!validateArgument(s, type))
			return false;
	}

	return true;
}

int parseCmd(int argc, char ** argv, G_Config config)
{
	//post cmd operations
	bool newProject = false;
	bool loadProject = false;

	//buffers
	string projName;

	for(int i = 1; i < argc; ++i)
	{
		int len = strlen(argv[i]);

		if (len == 1 || argv[0][0] != '-')
		{
			postCmdWrn("Options must be in format of -x, -xy, or --xyz\r\n");
			continue;
		}

		try
		{
			//full args
			if (argv[i][1] == '-')
			{
				vector<string> opt = splitString(argv[i], '=');
				unsigned long hash = fnv1a32(argv[i]);

				switch (hash)
				{
				case 86631055:	//--new
					newProject = true;
					break;
				case 565160199: //--load
					loadProject = true;
					break;
				case 1505474855://--maxnode
					if (validateArgument(argv[++i], _integer))
						config.maxNodes = atoi(argv[i]);
					else
						postCmdErr("Max Nodes argument must be an unsigned integer");
					break;
				case 3110576644://maxmem
					if (validateArgument(argv[++i], _integer))
						config.maxMb = atoi(argv[i]);
					else
						postCmdErr("Max Megabytes argument must be an unsigned integer");
					break;
				case 3772897447://maxthread
					if (validateArgument(argv[++i], _integer))
						config.maxThread = atoi(argv[i]);
					else
						postCmdErr("Max Thread argument must be an unsigned integer");
					break;
				default:
					postCmdErr("Unrecognized option : " + string(argv[i]));
					break;
				}
			}
			else
			{
				for (int j = 1; j < strlen(argv[i]); ++j)
				{
					switch (argv[i][j])
					{
					case 'd': config.debug = true; break;
					case 'v': config.verbose = true; break;
					case 'V': postVersion(); break;
					default:
						postCmdErr("Unrecognized option -" + string(argv[i][j], 1) + "\r\n");
					}
				}
			}
		} catch (const exception&e)
		{
			printc("Invalid command line argument\r\n", RED);
			postCmdErr(e.what());
		}
		
	}

	//verify post cmd operations
	if (newProject && loadProject)
	{
		printc("Cannot load and create a project simultaneously\r\n", RED);
		return errors |= 1;
	}

	//launch post cmd operations
	if (newProject) ProjectManager::NewProject(projName);
	if (loadProject) ProjectManager::LoadProject(projName);

	return errors;
}
