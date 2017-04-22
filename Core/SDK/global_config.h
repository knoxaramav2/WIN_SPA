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
	bool debug;

	//limits
	unsigned long maxNodes;
	unsigned maxThread;

	//modules
	vector<Version> moduleVersions;
};

#endif