#include "ModuleWindow.h"
#include "Globals.h"



ModuleWindow::ModuleWindow(bool is_enabled) : Module("window", is_enabled)
{
}


ModuleWindow::~ModuleWindow()
{
}

bool ModuleWindow::Awake(/* JSONDoc* config */)
{
	bool ret = true;

	INTERNAL_LOG("SDL Window and Surface Initialitzation ----------");

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		INTERNAL_LOG("SDL_VIDEO could not be initialized! SDL_Error: %s\n", SDL_GetError());
		ret = false;
	}
	else // SDL_Video is correctly initialized
	{
		// Create window 

		///HARDCODED VALUES FOR NOW, CHANGE THAT WHEN JSON CONFIG IS IMPLEMENTED
		current_title = "BeTroEngine v0.0.1";

		size = 1.0f;
		width = 500;
		height = 500;

		window_mode = SM_WINDOWED;
		resizable = true;

		/// --------------------------------------------------------------------

		Uint32 window_flags = SDL_WINDOW_SHOWN | SDL_WINDOW_VULKAN;

		switch (window_mode)
		{
		case SM_NULL:
			break;
		case SM_WINDOWED:
			break;
		case SM_WINDOWED_BORDERLESS:
			window_flags |= SDL_WINDOW_BORDERLESS;
			break;
		case SM_FULLSCREEN:
			window_flags |= SDL_WINDOW_FULLSCREEN;
			break;
		case SM_FULLSCREEN_DESKTOP:
			window_flags |= SDL_WINDOW_FULLSCREEN_DESKTOP;
			break;
		default:
			break;
		}

		if(resizable)
			window_flags |= SDL_WINDOW_RESIZABLE;

		window = SDL_CreateWindow(current_title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, window_flags);

		if (window == nullptr)
		{
			INTERNAL_LOG("Window could not be created! SDL Error: %s\n", SDL_GetError());
			ret = false;
		}
		else
		{
			INTERNAL_LOG("Window successfully created!\n");
		}
	}


	return ret;
}

bool ModuleWindow::CleanUp()
{
	INTERNAL_LOG("Destroying Window Module....\n");

	if (window != nullptr)
	{
		SDL_DestroyWindow(window);
	}

	SDL_Quit();

	return true;
}

void ModuleWindow::SetTitle(const char * new_title)
{
}

float ModuleWindow::GetSize() const
{
	return 0.0f;
}

int ModuleWindow::GetHeight() const
{
	return 0;
}

int ModuleWindow::GetWidth() const
{
	return 0;
}

const char * ModuleWindow::GetCurrentTitle() const
{
	return nullptr;
}

void ModuleWindow::ChangeBrightness(float brightness)
{
}

void ModuleWindow::SetFullScreen()
{
}

void ModuleWindow::SetFullScreenDesktop()
{
}

void ModuleWindow::SetWindowed()
{
}

void ModuleWindow::SetWindowSize(uint w, uint h)
{
}

void ModuleWindow::SetBorderless()
{
}
