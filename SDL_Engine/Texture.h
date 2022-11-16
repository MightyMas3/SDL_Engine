#pragma once
#include <SDL_image.h>
#include <string>
#include "vector.h"
#include "Screen.h"

class Texture
{

public:

	enum class Flip
	{
		None = SDL_FLIP_NONE,
		Vertical = SDL_FLIP_VERTICAL,
		Horizontal = SDL_FLIP_HORIZONTAL
	};

	Texture(int width = 0, int height = 0);

	bool Load(const std::string& filename, Screen& screen);
	void Unload();

	void IsAnimated(bool flag);
	void IsAnimationLooping(bool flag);

	void SetTextureDimension(int width, int height);
	void SetSourceDimension(int columns, int rows, int width, int height);
	void SetAnimationSpeed(float animationSpeed);

	void Update();
	void Render(Screen& screen, int x = 0, int y = 0, Flip flip = Flip::None);
	

private:
	
	int m_cel;
	float m_animationSpeed;
	float m_animationRunningTime;

	bool m_isAnimated;
	bool m_isAnimationDead;
	bool m_isAnimationLooping;
	bool m_isAnimationLoopFinal;

	SDL_Texture* m_texture;
	Vector<int> m_sourceDimension;
	Vector<int> m_celDimension;
	Vector<int> m_textureDimension;
	

};

