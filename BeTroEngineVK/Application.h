#ifndef _APPLICATION_H_
#define _APPLICATION_H_

#include "Globals.h"
#include <vector>

class Module;

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

private:
	int				   argc;
	char**			   args;

	bool			   exit_app = false;

	std::vector<Module*> modules;
};

extern Application* App;

#endif // !_APPLICATION_H_
