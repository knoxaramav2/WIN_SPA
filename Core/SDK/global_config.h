#pragma once
#ifndef GLOB_CFG
#define GLOB_CFG
#include "Version.h"
#include <vector>

/*
 * Shared between all modules
 */

struct G_Config
{
	G_Config();

	//core info
	Version coreVersion;
	Version sdkVersion;
	Version cnsVersion;

	//switches
	bool verbose;

	//limits
	unsigned long maxNodes;

	//modules
	vector<Version> moduleVersions;
};

#endif