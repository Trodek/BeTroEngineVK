#ifndef _APPLICATION_H_
#define _APPLICATION_H_

#include "Globals.h"
#include <vector>

class Module;
class ModuleWindow;

class Application
{
public:
	Application(int argc, char* args[]);
	~Application();

	bool Awake();
	bool Start();
	bool Update();
	bool CleanUp();

	void ExitApp();

	std::string GetAppName() const;
	std::string GetAppVersion() const;

public:
	// Application Modules

	ModuleWindow * window = nullptr;

	// -------------------

private:
	void AddModule(Module* mod);

private:
	int				     argc = 0;
	char**			     args = nullptr;

	bool			     app_exit = false;

	std::string		     app_name;
	std::string			 app_version;

	std::vector<Module*> modules;
};

extern Application* App;

#endif // !_APPLICATION_H_
