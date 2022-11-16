#include "Input.h"
#include "Player.h"

Player::Player(Screen& screen)
{
	m_velocity = 1;

	m_idle.Load("Images/Player/Movement/idle.png", screen);
	m_idle.SetTextureDimension(128, 128);
	m_idle.SetSourceDimension(9, 1, 576, 64);
	m_idle.IsAnimated(true);
	m_idle.IsAnimationLooping(true);
	m_idle.SetAnimationSpeed(0.3f);
	
	m_run.Load("Images/Player/Movement/run.png", screen);
	m_run.SetTextureDimension(128, 128);
	m_run.SetSourceDimension(8, 1, 512, 64);
	m_run.IsAnimated(true);
	m_run.IsAnimationLooping(true);
	m_run.SetAnimationSpeed(0.3f);

	m_position.x = 100;
	m_position.y = 100;
}

void Player::Update()
{
	auto keys = Input::Instance()->GetKey();

	//keyboard input check and player direction setting
	/*if (Input::Instance()->IsKeyPressed(HM_KEY_A))
	{
		m_directionStand = m_directionRun = Vector<int>::Left;
	}
	
	else if (Input::Instance()->IsKeyPressed(HM_KEY_D))
	{
		m_directionStand = m_directionRun = Vector<int>::Right;
	}*/
	
	if (Input::Instance()->IsKeyPressed(HM_KEY_W))
	{
		m_directionStand = m_directionRun = Vector<int>::Down;
	}
	
	else if (Input::Instance()->IsKeyPressed(HM_KEY_S))
	{
		m_directionStand = m_directionRun = Vector<int>::Up;
	}
	
	else
	{
		m_directionRun = Vector<int>::Zero;
	}

	m_position += m_directionRun * m_velocity;

	m_idle.Update();
	m_run.Update();
}


bool Player::Render(Screen& screen)
{
	if (m_directionRun.x == 0 && m_directionRun.y == 0)
	{
		m_directionStand.x < 0.0f ? m_idle.Render(screen, m_position.x, m_position.y, Texture::Flip::Horizontal)
			: m_idle.Render(screen, m_position.x, m_position.y);
	}

	else
	{
		m_directionRun.x < 0.0f ? m_run.Render(screen, m_position.x, m_position.y, Texture::Flip::Horizontal)
			: m_run.Render(screen, m_position.x, m_position.y);
	}

	return true;
}

Player::~Player()
{
	m_run.Unload();
	m_idle.Unload();
}