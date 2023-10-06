#pragma once
#include<SFML/Window.hpp>
#include <string>

#include"Indi.h"
#include"Score.h"
#include"soundEffect.h"
#include"Ddong_GEN.h"

class Engine
{
private:
	RenderWindow window;
	Event event;

	Font font;
	Text text;
	Text Level;
	Text Level1;

	soundEffect s;
	Indi indi;
	Ddong_GEN ddongs;
	Score score;

	int cur_score;
	int level = 0;

	void GameOver();
	void render();

public:
	Engine();
	void loop();
};