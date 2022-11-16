#include <iostream>
#include "Game.h"

bool Game::Initialize()
{
    m_screen.initialize();
	m_player = std::make_unique<Player>(m_screen);

    m_background.Load("Images/Desert_Midday1.png", m_screen);
    m_background.SetSourceDimension(1, 1, 1280, 766);

    m_music.Initialize();
    m_music.Load("Music/Adventure_Fantasy Track 4.wav");
    m_music.SetVolume(0.2f);
    m_music.Play(Music::Loop::Ongoing);

    m_score.Initialize();
    m_score.Load("Fonts/OCRAEXT.ttf");
    m_score.SetSize(150, 75);
    m_score.SetColor(0, 0, 0);
    m_score.SetString("Score: 0");

    /*
    m_title.Initialize();
    m_title.Load("Fonts/BAUHS93.ttf");
    m_title.SetSize(500, 200);
    m_title.SetColor(139, 69, 19);
    m_title.SetString("MY AMAZING GAME ENGINE");*/

	

    return true;
}

void Game::Run()
{
	while (m_isGameRunning)
	{
		m_screen.present();

		Input::Instance()->Update();

		m_isGameRunning = !(Input::Instance()->IsWindowClosed());

		//Vector<int> mousePosition = Input::Instance()->GetMousePosition();
		//Vector<int> mouseMotion = Input::Instance()->GetMouseMotion();
		//Vector<int> mouseWheel = Input::Instance()->GetMouseWheel();


		//std::cout << "Mouse motion: " << mouseMotion.x << ", " << mouseMotion.y << std::endl;

		//std::cout << Input::Instance()->GetKey() << std::endl;

		//if (Input::Instance()->IsKeyPressed(HM_KEY_SPACE) == true)
		//{
		//	std::cout << "space key pressed " << std::endl;
		//}

		m_background.Render(m_screen, 0, 0);

		m_player->Update();
		m_player->Render(m_screen);

		//title.Render(screen, 400, 250);

		m_score.Render(m_screen, 10, 10);

		m_screen.present();
	}
}

void Game::Shutdown()
{
	m_music.Unload();
	m_music.Shutdown();
	
	//m_title.Unload();
	//m_title.Shutdown();
	
	m_score.Unload();
	m_score.Shutdown();
	
	m_background.Unload();
	
	m_screen.shutdown();
}
