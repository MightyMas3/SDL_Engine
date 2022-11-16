#pragma once
#include <memory>
#include "Texture.h"
#include "Input.h"
#include "Player.h"
#include "Screen.h"
#include "Music.h"
#include "Text.h"

class Game
{

public:

	bool Initialize();
	void Run();
	void Shutdown();

private:
	Text score;
	//Text title;
	Music music;
	Screen screen;

	bool isGameRunning{ true };
	Texture background{ 1280, 766 };
	
	std::unique_ptr<Player> player;
	
	
};

