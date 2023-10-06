#include<SFML/Graphics.hpp>
#include<iostream>
#include <vector>
#include "GameBoard.h"
#include"mouseClick.h"
#include"SimonSays.h"
#include"playSound.h"


using namespace std;
using namespace sf;

int main() {
	srand((unsigned int)time(NULL));
	RenderWindow window(VideoMode(800, 800), "Simon Game");
	window.setFramerateLimit(30);
	Event event;
	mouseClick mouse;
	SimonSays simon;
	playSound sound;

	int n = 4;
	bool start_flag = true;
	CircleShape c(100.0f);
	c.move(150.0f, 300.0f);
	c.setFillColor(Color::Black);

	CircleShape up(100.0f, 3);
	up.move(500.0f, 150.0f);
	up.setFillColor(Color::Black);

	CircleShape down(100.0f, 3);
	down.rotate(180.0f);
	down.move(700.0f, 650.0f);
	down.setFillColor(Color::Black);

	Font font;
	if (!font.loadFromFile("arial.ttf"))
	{
	}
	Text text;
	text.setFont(font);
	text.setFillColor(Color::White);
	text.setCharacterSize(30);

	Text text1;
	text1.setFont(font);
	text1.setFillColor(Color::Black);
	text1.setCharacterSize(50);
	

	while (start_flag) {
		window.pollEvent(event);
		mouse.updateMouse(window);
		window.clear(Color::White);
		window.draw(c);
		window.draw(up);
		window.draw(down);

		text.setPosition(215.0f, 375.0f);
		text.setString(String("Start!"));
		window.draw(text);

		text.setPosition(585.0f, 220.0f);
		text.setString(String("Up"));
		window.draw(text);

		text.setPosition(565.0f, 520.0f);
		text.setString(String("Down"));
		window.draw(text);

		text1.setPosition(10.0f, 10.0f);
		text1.setString(String("The number of the button : "));
		window.draw(text1);

		text1.setPosition(610.0f, 10.0f);
		text1.setString(to_string(n));
		window.draw(text1);

		window.display();

		switch (event.type) {
		case Event::Closed:
			window.close();

		case Event::MouseButtonPressed:
			if (Mouse::isButtonPressed(Mouse::Left) and
				up.getGlobalBounds().contains(mouse._mouse) and n < 10) {
				n++;
			}
			if (Mouse::isButtonPressed(Mouse::Left) and
				down.getGlobalBounds().contains(mouse._mouse) and n > 4) {
				n--;
			}
			if (Mouse::isButtonPressed(Mouse::Left) and
				c.getGlobalBounds().contains(mouse._mouse)) {
				start_flag = false;
			}
		}
	}

	GameBoard gameboard(n);
	simon.generate(gameboard, window, sound);

	while (window.isOpen()) {
		mouse.updateMouse(window);

		while (window.pollEvent(event)) {
			switch (event.type) {
			case Event::Closed:
				window.close();
				break;

			case Event::MouseButtonPressed:
				if (Mouse::isButtonPressed(Mouse::Left)) {
					gameboard.updateBoard(mouse.whichOne(gameboard), window, sound);
					cout << mouse.isCorrect(gameboard, simon, window, sound) << endl;
				}
			}
		}
		gameboard.updateBoard(-1, window, sound);
		gameboard.drawBoard(window);
	}

	return 0;
}