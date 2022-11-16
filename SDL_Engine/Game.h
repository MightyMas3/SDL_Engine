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
	Text m_score;
	//Text m_title;
	Music m_music;
	Screen m_screen;

	bool m_isGameRunning{ true };
	Texture m_background{ 1280, 766 };
	
	std::unique_ptr<Player> m_player;
	
	
};

