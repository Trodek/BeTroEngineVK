#include "Application.h"



Application::Application()
{
}


Application::~Application()
{
}

bool Application::Init()
{
	return true;
}

update_status Application::Update()
{
	return update_status::UPDATE_CONTINUE;
}

bool Application::CleanUp()
{
	return true;
}
