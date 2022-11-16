#pragma once

#include "Texture.h"
#include "Vector.h"

class Player
{

public:

	Player(Screen& screen);
	~Player();

	void Update();
	bool Render(Screen& screen);

private:

	int m_velocity;

	Texture m_idle;
	Texture m_run;

	Vector<int> m_position;
	Vector<int> m_directionRun;
	Vector<int> m_directionStand;

};