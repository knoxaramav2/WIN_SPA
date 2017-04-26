#pragma once
#ifndef PROJECT_MANAGER
#define PROJECT_MANAGER

#include <vector>

using namespace std;

class ProjectHandle
{
	string _name;

public:



};

class ProjectManager
{
	
	static ProjectHandle * Current;

public:

	ProjectManager();

	static ProjectHandle * NewProject(string name);
	static ProjectHandle * LoadProject(string name);

};

#endif