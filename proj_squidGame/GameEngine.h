#pragma once
#include<SFML/Graphics.hpp>
#include<Windows.h>
#include"Resources.h"
#include"Tagger.h"
#include"Player.h"

using namespace sf;

class GameEngine
{
private:
	RenderWindow window;
	Event event;
	Resources resources;

	Player* player;
	Player* NPC1;
	Player* NPC2;
	Player* NPC3;
	Player* NPC4;
	Player* NPC5;
	Tagger tagger;

	Font font;
	Text text;
	Clock c;
	Time t;

	bool start_flg = false;
	int wait_time1, wait_time2, wait_time3, wait_time4, wait_time5, Pwait_time;

public:
	GameEngine();
	void handleMovement();
	void render();
	void loop();
};