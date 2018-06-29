#ifndef __MODULEWINDOW__
#define __MODULEWINDOW__

#include <string>
#include "Module.h"
#include "Source/SDL2/include/SDL.h"

enum SCREEN_MODE
{
	SM_NULL,
	SM_WINDOWED,
	SM_WINDOWED_BORDERLESS,
	SM_FULLSCREEN,
	SM_FULLSCREEN_DESKTOP,
};

class ModuleWindow : public Module
{
public:
	ModuleWindow(bool is_enabled = true);
	~ModuleWindow();

	//Module virtual functions
	bool Awake(/* JSONDoc* config */);
	bool CleanUp();

	void SetTitle(const char* new_title);

	float GetSize() const;
	int GetHeight() const;
	int GetWidth() const;

	const char* GetCurrentTitle() const;

private:
	void ChangeBrightness(float brightness);
	void SetFullScreen();
	void SetFullScreenDesktop();
	void SetWindowed();
	void SetWindowSize(uint w, uint h);
	void SetBorderless();

public: 
	SDL_Window* window = nullptr;

	SDL_Surface* screen_surface = nullptr;

private:
	std::string current_title;

	float size;
	int width, height;
	float brightness = 1.0f;
	SCREEN_MODE window_mode = SM_NULL;

	bool resizable = false;
};


#endif // !__MODULEWINDOW__


