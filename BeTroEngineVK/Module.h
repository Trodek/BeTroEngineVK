#ifndef _MODULE_H_
#define _MODULE_H_

#include "Globals.h"

#include <string>

class Module
{
public:
	Module(const char* name)
	{
		module_name = name;
	}

	virtual ~Module()
	{}

	virtual bool Awake()
	{
		return true;
	}

	virtual bool Start()
	{
		return true;
	}

	virtual bool PreUpdate()
	{
		return true;
	}

	virtual bool Update()
	{
		return true;
	}

	virtual bool PostUpdate()
	{
		return true;
	}

	virtual bool CleanUp()
	{
		return true;
	}

	//virtual void OnLoadConfig(JSON_Doc* config) {};
	//virtual void OnSaveConfig(JSON_Doc* config) {};

	void SetEnabled(const bool& set) 
	{ 
		enabled = set; 
	};
	bool GetEnabled() const
	{
		return enabled; 
	};

	std::string GetName() const 
	{ 
		return module_name; 
	};

private:
	bool        enabled = true;
	std::string module_name = "null";
};

#endif // !_MODULE_H_