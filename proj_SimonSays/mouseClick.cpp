#include "mouseClick.h"

void mouseClick::updateMouse(RenderWindow& _window) {
	_mouse = _window.mapPixelToCoords(Mouse::getPosition(_window));
	return;
}

int mouseClick::whichOne(class GameBoard& _g) {
	for (int i = 0; i < _g.howMany; i++) {
		if (_g.board.at(i).getGlobalBounds().contains(_mouse)) {
			return i;
		}
	}
	return -1;
}

bool mouseClick::isCorrect(class GameBoard& _g, class SimonSays& _simon, RenderWindow& _window, class playSound& _sound) {
	if (whichOne(_g) == _simon.queue.at(_simon.queue_ind)) {
		_simon.queue_ind++;
		if (_simon.queue_ind == _simon.queue.size()) {
			_simon.updateSimon();
			_simon.generate(_g, _window, _sound);
		}
		return true;
	}
	else return false;
}