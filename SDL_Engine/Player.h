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

	int velocity;

	Texture idle;
	Texture run;

	Vector<int> position;
	Vector<int> directionRun;
	Vector<int> directionStand;

};