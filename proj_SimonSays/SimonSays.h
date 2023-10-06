#pragma once
#include<SFML/Graphics.hpp>
#include<Windows.h>
#include <vector>
#include"GameBoard.h"
#include"playSound.h"


using namespace std;
using namespace sf;

class SimonSays {
public:
	vector<int> queue;
	int level = 1;
	int queue_ind = 0;
	void generate(class GameBoard& _g, RenderWindow& _window, class playSound& _sound);
	void updateSimon();
};
