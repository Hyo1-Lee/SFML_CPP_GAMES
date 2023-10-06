#include "GameBoard.h"

GameBoard::GameBoard(int _n) {
	howMany = _n;
	cntNum = 120;
	c1 = CircleShape(350.0f);
	c1.setPointCount(cntNum);

	c2 = CircleShape(100.0f);
	c2.setPointCount(cntNum);

	for (int k = 0; k < _n; k++) {
		board.push_back(ConvexShape(cntNum / howMany * 2));

		int i = 0;
		int c_i = cntNum / howMany * k;
		for (i; i < cntNum / howMany; i++) {
			board.at(k).setPoint(i, c1.getPoint(c_i));
			c_i++;
		}
		int j = c_i - 1;
		for (i; i < cntNum / howMany * 2; i++) {
			board.at(k).setPoint(i, Vector2f(c2.getPoint(j).x + 250.0f, c2.getPoint(j).y + 250.0f));
			j--;
		}
		board.at(k).move(50.0f, 50.0f);
		board.at(k).setFillColor(colors[k]);
	}
}

void GameBoard::drawBoard(RenderWindow& _window) {
	_window.clear();
	for (int i = 0; i < howMany; i++) {
		_window.draw(board.at(i));
	}
	_window.display();
}

void GameBoard::updateBoard(int _n, RenderWindow& _window, class playSound& _sound) {
	if (_n >= 0 and _n <= 9) {
		board.at(_n).setFillColor(fillColors[_n]);
		_sound.setNote(_n);
		_sound.on();
		clock.restart();
		_window.clear();
		drawBoard(_window);
	}
	time = clock.getElapsedTime();
	
	if (time.asSeconds() >= 0.15f) {
		eraseColors();
		_sound.off();
	}
}

void GameBoard::eraseColors() {
	for (int i = 0; i < howMany; i++) {
		board.at(i).setFillColor(colors[i]);
	}
}