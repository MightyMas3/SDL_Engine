#include <iostream>
#include "Game.h"

int main(int argc, char* argv[])
{
	Game game;
	game.Initialize();
	game.Run();
	game.Shutdown();

	return 0;
	}