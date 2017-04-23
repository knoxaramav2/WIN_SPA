#pragma once
#ifndef DLL_MODULE
#define DLL_MODULE

#include <windows.h>
#include "Version.h"

class Module
{
	
	HINSTANCE	_handle;
	Version		_version;
	string		_id;

public:

	Module();

};

#endif