#pragma once
#include<SFML/Graphics.hpp>
#include "GameBoard.h"
#include"SimonSays.h"
#include"playSound.h"

using namespace sf;

class mouseClick {
public:
	Vector2f _mouse;
	void updateMouse(RenderWindow& _window);
	int whichOne(class GameBoard& _g);
	bool isCorrect(class GameBoard& _g, class SimonSays& _simon, RenderWindow& _window, class playSound& _sound);
};