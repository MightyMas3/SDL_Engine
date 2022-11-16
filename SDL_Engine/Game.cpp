#include <iostream>
#include "Game.h"

bool Game::Initialize()
{
    screen.initialize();
	player = std::make_unique<Player>(screen);

    background.Load("Images/Desert_Midday1.png", screen);
    background.SetSourceDimension(1, 1, 1280, 766);

    music.Initialize();
    music.Load("Music/Adventure_Fantasy Track 4.wav");
    music.SetVolume(0.2f);
    music.Play(Music::Loop::Ongoing);

    score.Initialize();
    score.Load("Fonts/OCRAEXT.ttf");
    score.SetSize(150, 75);
    score.SetColor(0, 0, 0);
    score.SetString("Score: 0");

    /*
    title.Initialize();
    title.Load("Fonts/BAUHS93.ttf");
    title.SetSize(500, 200);
    title.SetColor(139, 69, 19);
    title.SetString("MY AMAZING GAME ENGINE");*/

	

    return true;
}

void Game::Run()
{
	while (isGameRunning)
	{
		screen.present();

		Input::Instance()->Update();

		isGameRunning = !(Input::Instance()->IsWindowClosed());

		//Vector<int> mousePosition = Input::Instance()->GetMousePosition();
		//Vector<int> mouseMotion = Input::Instance()->GetMouseMotion();
		//Vector<int> mouseWheel = Input::Instance()->GetMouseWheel();


		//std::cout << "Mouse motion: " << mouseMotion.x << ", " << mouseMotion.y << std::endl;

		//std::cout << Input::Instance()->GetKey() << std::endl;

		//if (Input::Instance()->IsKeyPressed(HM_KEY_SPACE) == true)
		//{
		//	std::cout << "space key pressed " << std::endl;
		//}

		background.Render(screen, 0, 0);

		player->Update();
		player->Render(screen);

		//title.Render(screen, 400, 250);

		score.Render(screen, 10, 10);

		screen.present();
	}
}

void Game::Shutdown()
{
	music.Unload();
	music.Shutdown();
	
	//title.Unload();
	//title.Shutdown();
	
	score.Unload();
	score.Shutdown();
	
	background.Unload();
	
	screen.shutdown();
}
