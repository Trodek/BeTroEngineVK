#include "Application.h"
#include "ModuleWindow.h"

Application::Application(int argc, char* args[]) : argc(argc), args(args)
{
	// Modules Creation
	window = new ModuleWindow();

	// Add moduels to modules vector
	AddModule(window);
}

Application::~Application()
{
}

bool Application::Awake()
{
	bool ret = true;

	for (std::vector<Module*>::iterator mod = modules.begin(); mod != modules.end() && ret; ++mod)
	{
		if ((*mod)->GetEnabled())
			ret = (*mod)->Awake();

		if (!ret)
			INTERNAL_LOG("Error on Awake: Module %s", (*mod)->GetName().c_str());
	}

	return ret;
}

bool Application::Start()
{
	bool ret = true;

	for (std::vector<Module*>::iterator mod = modules.begin(); mod != modules.end() && ret; ++mod)
	{
		if ((*mod)->GetEnabled())
			ret = (*mod)->Start();

		if (!ret)
			INTERNAL_LOG("Error on Start: Module %s", (*mod)->GetName().c_str());
	}

	return ret;
}

bool Application::Update()
{
	bool ret = true;

	for (std::vector<Module*>::iterator mod = modules.begin(); mod != modules.end() && ret; ++mod)
	{
		if ((*mod)->GetEnabled())
			ret = (*mod)->Update();

		if (!ret)
			INTERNAL_LOG("Error on Update: Module %s", (*mod)->GetName().c_str());
	}

	if (app_exit)
		ret = false;

	return ret;
}

bool Application::CleanUp()
{
	bool ret = true;

	for (std::vector<Module*>::iterator mod = modules.begin(); mod != modules.end() && ret; ++mod)
	{
		ret = (*mod)->CleanUp();

		if (!ret)
			INTERNAL_LOG("Error on Clean Up: Module %s", (*mod)->GetName().c_str());
	}

	return ret;
}

void Application::ExitApp()
{
	app_exit = true;
}

std::string Application::GetAppName() const
{
	return app_name;
}

std::string Application::GetAppVersion() const
{
	return app_version;
}

void Application::AddModule(Module * mod)
{
	modules.push_back(mod);
}
