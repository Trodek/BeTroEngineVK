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

	if (exit_app)
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
	exit_app = true;
}
