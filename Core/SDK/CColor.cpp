#include <wincon.h>
#include <stdio.h>

#include "CColor.h"


void printc(string msg, int color)
{
	printf("%s\r\n", msg.c_str());
}
