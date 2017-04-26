#pragma once
#ifndef PROJ_MANAGE
#define PROJ_MANAGE

#ifdef MANAGE_EXPORTS
#define MANAGE_EXPORTS_API __declspec(dllexport)
#else
#define MANAGE_EXPORTS_API __declspec(dllimport)
#endif
#include <string>

namespace PManager
{
	class ProjectHandle
	{
		
	};

	class ProjectManager
	{

	public:
		static MANAGE_EXPORTS_API ProjectHandle NewProject(std::string name);
		static MANAGE_EXPORTS_API ProjectHandle LoadProject(std::string name);
	};
}

#endif