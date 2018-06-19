#include "Application.h"

Application::Application(int argc, char* args[]) : argc(argc), args(args)
{
}

Application::~Application()
{
}

bool Application::Awake()
{
	bool ret = true;

	return ret;
}

bool Application::Start()
{
	bool ret = true;

	return ret;
}

bool Application::Update()
{
	bool ret = true;

	if (app_exit)
		ret = false;

	return ret;
}

bool Application::CleanUp()
{
	bool ret = true;

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
