#include "global_config.h"

G_Config::G_Config()
{
	//switches
	verbose = false;
	debug = false;

	//limits
	maxNodes = 1000;
	maxThread = 6;
}
