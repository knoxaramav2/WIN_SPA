#pragma once
#ifndef MODULES
#define MODULES

#include <vector>
#include <string>

#include "../SDK/Module.h"

class ModuleManager
{
	vector<Module> _modules;

public:

	ModuleManager();

	void LoadModule();
	void LoadModuleFolder(string path);
};

#endif