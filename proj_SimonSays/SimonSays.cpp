#include"SimonSays.h"

void SimonSays::generate(class GameBoard& _g, RenderWindow& _window, class playSound& _sound) {
	Sleep(150);
	_sound.off();
	_g.eraseColors();
	_g.drawBoard(_window);
	Sleep(1000);
	for (int i = 0; i < level + 1; i++) {
		queue.push_back(rand() % _g.howMany);
		_g.updateBoard(queue.at(i), _window, _sound);
		_sound.setNote(queue.at(i));
		_sound.on();

		Sleep(1000 - level * 100);
		_g.eraseColors();
		_g.drawBoard(_window);
		_sound.off();
		Sleep(100);
	}
}

void SimonSays::updateSimon() {
	level++;
	for (int i = 0; i < queue_ind; i++) {
		queue.pop_back();
	}
	queue_ind = 0;
}