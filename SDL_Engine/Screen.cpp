#include <iostream>
#include "Screen.h"

Screen::Screen()
{
	m_window = nullptr;
	m_renderer = nullptr;
}

Screen::~Screen()
{

}

SDL_Renderer* Screen::GetRenderer()
{
	return m_renderer;
}

bool Screen::initialize()
{

	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		std::cout << "SDL did not initialize!" << std::endl;
		return false;
	}

	m_window = SDL_CreateWindow("My awesome game engine!",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		1280, 720,
		0);

	if (!m_window) // window is a nullptr so if not (!) 0, is 1 so true
	{
		std::cout << "Game window could not be created!" << std::endl;
		return false;
	}

	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);

	if (!m_renderer)
	{
		std::cout << "Renderer could not be created!" << std::endl;
		return false;
	}

	return true;
}

void Screen::refresh()
{
	//clears the screen
	SDL_RenderClear(m_renderer);
}

void Screen::present()
{
	//swaps the frame buffers
	SDL_RenderPresent(m_renderer);
}

void Screen::shutdown()
{
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}
