#pragma once
#include<SFML/Graphics.hpp>

using namespace sf;

class Animation
{
private:
	IntRect* bounds;
	int frames;
	Clock clock;
	int resetValue;

public:
	Animation(IntRect* rect, int framesNuber);
	void changeFrame(float _speed);
	void changeBoomFrame(float _speed);
	IntRect getBounds();
};