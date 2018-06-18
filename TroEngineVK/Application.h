#ifndef _APPLICATION_H_
#define _APPLICATION_H_

#include "Globals.h"
#include <vector>

class Module;

class Application
{
public:
	Application();
	~Application();

	bool Init();
	update_status Update();
	bool CleanUp();

private:
	std::vector<Module*> modules;


};

extern Application* App;

#endif // !_APPLICATION_H_
