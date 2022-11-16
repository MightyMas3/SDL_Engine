#include "Input.h"
#include "Player.h"

Player::Player(Screen& screen)
{
	velocity = 1;

	idle.Load("Images/Player/Movement/idle.png", screen);
	idle.SetTextureDimension(128, 128);
	idle.SetSourceDimension(9, 1, 576, 64);
	idle.IsAnimated(true);
	idle.IsAnimationLooping(true);
	idle.SetAnimationSpeed(0.3f);
	
	run.Load("Images/Player/Movement/run.png", screen);
	run.SetTextureDimension(128, 128);
	run.SetSourceDimension(8, 1, 512, 64);
	run.IsAnimated(true);
	run.IsAnimationLooping(true);
	run.SetAnimationSpeed(0.3f);

	position.x = 100;
	position.y = 100;
}

void Player::Update()
{
	auto keys = Input::Instance()->GetKey();

	//keyboard input check and player direction setting
	/*if (Input::Instance()->IsKeyPressed(HM_KEY_A))
	{
		directionStand = directionRun = Vector<int>::Left;
	}
	
	else if (Input::Instance()->IsKeyPressed(HM_KEY_D))
	{
		directionStand = directionRun = Vector<int>::Right;
	}*/
	
	if (Input::Instance()->IsKeyPressed(HM_KEY_W))
	{
		directionStand = directionRun = Vector<int>::Down;
	}
	
	else if (Input::Instance()->IsKeyPressed(HM_KEY_S))
	{
		directionStand = directionRun = Vector<int>::Up;
	}
	
	else
	{
		directionRun = Vector<int>::Zero;
	}

	position += directionRun * velocity;

	idle.Update();
	run.Update();
}


bool Player::Render(Screen& screen)
{
	if (directionRun.x == 0 && directionRun.y == 0)
	{
		directionStand.x < 0.0f ? idle.Render(screen, position.x, position.y, Texture::Flip::Horizontal)
			: idle.Render(screen, position.x, position.y);
	}

	else
	{
		directionRun.x < 0.0f ? run.Render(screen, position.x, position.y, Texture::Flip::Horizontal)
			: run.Render(screen, position.x, position.y);
	}

	return true;
}

Player::~Player()
{
	run.Unload();
	idle.Unload();
}