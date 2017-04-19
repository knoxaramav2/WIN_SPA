#include "Version.h"
#include "global_config.h"


Version::Version()
{
	version = "";
}

Version::Version(int major, int minor, int patch)
{
	version =
		to_string(major) + '.' +
		to_string(minor) + '.' +
		to_string(patch);
}

int Version::GetMajor() const
{
	int index = version.find_first_of('.');
	return atoi(version.substr(0, index).c_str());
}

int Version::GetMinor() const
{
	return atoi(version.substr(
		version.find_first_of('.'),
		version.find_last_of('.')
	).c_str());
}

int Version::GetPatch() const
{
	return atoi(version.substr(
		version.find_last_of('.'),
		version.length()
	).c_str());
}
