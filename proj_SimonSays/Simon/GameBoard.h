#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include <vector>
#include"playSound.h"

using namespace std;
using namespace sf;

class GameBoard {
private:
	CircleShape c1;
	CircleShape c2;
	Color fillColors[10] = { Color::Color(255,0,0), Color::Color(0,0,255), Color::Color(255,255,0),Color::Color(0,255,0),Color::Color(255,0,255),
						Color::Color(0,255,255), Color::Color(255,255,255), Color::Color(128,255,128), Color::Color(0,64,255), Color::Color(255,255,64) };
	Color colors[10] = { Color::Color(255,0,0,70), Color::Color(0,0,255,70), Color::Color(255,255,0,70),Color::Color(0,255,0,70),Color::Color(255,0,255,70),
						Color::Color(0,255,255,70), Color::Color(255,255,255,70), Color::Color(128,255,128,70), Color::Color(0,64,255,70), Color::Color(255,255,64,70) };
	Clock clock;
	Time time;
public:
	vector<ConvexShape> board;
	GameBoard(int _n);
	int cntNum;
	int howMany;
	void drawBoard(RenderWindow& _window);
	void updateBoard(int _n, RenderWindow& _window, class playSound& _sound);
	void eraseColors();
};