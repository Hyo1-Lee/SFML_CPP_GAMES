#pragma once
#include "Score.h"

using namespace std;

class Ddong
{
private:
	float x;
	float speed;
	Texture t;

public:
	Sprite Dd;
	bool destroyed = false;
	Ddong(float _x, float _speed);
	void update(Score& score);
	void draw(RenderWindow& _window);
	FloatRect getArea();
};