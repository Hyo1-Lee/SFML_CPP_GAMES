#pragma once
#include <vector>
#include <random>
#include <cstdlib>
#include <ctime>
#include "Ddong.h"
#include "Score.h"

class Ddong_GEN
{
private:
	vector<Ddong> ddongs;
	int ddong_gen_period;
	int ddong_speed;
public:
	Ddong_GEN();
	void update(Score& score);
	void draw(RenderWindow& _window);
	bool checkHit(FloatRect _rect);
	void levelUp();
};