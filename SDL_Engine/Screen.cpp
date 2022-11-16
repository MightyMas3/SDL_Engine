#include <iostream>
#include "Screen.h"

Screen::Screen()
{
	window = nullptr;
	renderer = nullptr;
}

//TODO - Remove
Screen::~Screen()
{

}

SDL_Renderer* Screen::GetRenderer()
{
	return renderer;
}

bool Screen::initialize()
{

	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		std::cout << "SDL did not initialize!" << std::endl;
		return false;
	}

	window = SDL_CreateWindow("My awesome game engine!",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		1280, 720,
		0);

	if (!window) // window is a nullptr so if not (!) 0, is 1 so true
	{
		std::cout << "Game window could not be created!" << std::endl;
		return false;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	if (!renderer)
	{
		std::cout << "Renderer could not be created!" << std::endl;
		return false;
	}

	return true;
}

void Screen::refresh()
{
	//clears the screen
	SDL_RenderClear(renderer);
}

void Screen::present()
{
	//swaps the frame buffers
	SDL_RenderPresent(renderer);
}

void Screen::shutdown()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
