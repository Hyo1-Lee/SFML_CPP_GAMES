#pragma once
#include<SFML/Graphics.hpp>
#include<stack>
#include"GameState.h"

class StateManager
{
private:
	std::stack<GameState*> states;
public:
	void addState(GameState* state);
	void loop();
	void render(sf::RenderWindow* window);
	void keyPressed(int code);
	void keyReleased(int code);
};