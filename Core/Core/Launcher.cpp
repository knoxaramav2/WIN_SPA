#include <string>
#include "../SDK/global_config.h"
#include "../SDK/CColor.h"
#include "MathUtil.h"

G_Config config;

int parseCmd(int argc, char ** argv)
{
	int ret = 0;

	for(int i = 1; i < argc; ++i)
	{
		string arg = string(argv[i]);

		if (arg[0]!='-')
		{
			printc("Invalid opton ["+string(argv[i])+"]", RED);
			continue;
		}

		if (argv[i][1]=='-')
		{
			if (arg == "--maxnode" && isInteger(argv[++i]))
			{
				config.maxNodes = atoi(argv[i]);
			} else if (arg == "--maxThreads" && isInteger(argv[++i]))
			{
				config.maxThread = atoi(argv[i]);
			} else
			{
				printf("Unrecognized option %s\r\n", argv[i]);
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
					printf("Unrecognized option -%c\r\n", argv[i][j]);
				}
			}
		}
	}
	
	return ret;
}

int main(int argc, char ** argv)
{
	int rcode = parseCmd(argc, argv);
	if (rcode != 0) return rcode;

	//detect and load modules

	//load network state

	//execute

	//save state

	return 0;
}