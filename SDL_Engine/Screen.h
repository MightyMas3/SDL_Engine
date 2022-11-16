#pragma once
#include <SDL.h>

class Screen
{

public:

	Screen();
	~Screen();

	SDL_Renderer* GetRenderer();

	bool initialize();
	void refresh();
	void present();
	void shutdown();



private:
	
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;

};

