#include <string>
#include "../SDK/global_config.h"
#include "../SDK/CColor.h"

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
			
		}else
		{
			for(int j = 1; j < strlen(argv[i]); ++j)
			{
				switch(argv[i][j])
				{
					
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



	return 0;
}