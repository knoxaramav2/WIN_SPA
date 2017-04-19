#pragma once
#ifndef VERSION
#define VERSION

#include <string>

using namespace std;

struct Version
{
	string version;

	/**
	 * Template for module versioning
	 */
	Version();
	Version(int, int, int);
	int GetMajor() const;
	int GetMinor() const;
	int GetPatch() const;
};

#endif