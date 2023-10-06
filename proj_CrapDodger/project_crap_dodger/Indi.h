#pragma once
#include <vector>
#include "Ddong_GEN.h"
#include "Score.h"
#include "soundEffect.h"

class Indi
{
private:
	bool hitted;
	int hit_time;
	Texture tt;
	Sprite indi;
	Texture t;
	
public:
	Indi();
	void moveIndi();
	void update(Ddong_GEN& ddongs, Score& score, soundEffect& s);
	void draw(RenderWindow& _window);
	float speed;
	bool flag = false;
	bool jumpFlag = true;
	vector<Sprite> life;
};