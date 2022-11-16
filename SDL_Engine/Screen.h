#pragma once
#include <SDL.h>

//TODO - Make a Singleton
//TODO - Tidy code

class Screen
{

public:

	Screen();
	~Screen();

	SDL_Renderer* GetRenderer();

	//TODO - Use Pascal case
	//TODO - Pass arguments to setup the screen
	bool initialize();
	void refresh();
	void present();
	void shutdown();



private:
	
	SDL_Window* window;
	SDL_Renderer* renderer;

};

