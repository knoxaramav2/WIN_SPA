#include <stdio.h>
#include <windows.h>

#include "CColor.h"


void printc(string msg, int color)
{
	CONSOLE_SCREEN_BUFFER_INFO info;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsole, &info);

	SetConsoleTextAttribute(hConsole, color);
	printf("%s", msg.c_str());
	SetConsoleTextAttribute(hConsole, info.wAttributes);
}
