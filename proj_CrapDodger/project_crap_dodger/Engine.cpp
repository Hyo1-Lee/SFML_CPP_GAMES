#include "Engine.h"

Engine::Engine(){
	window.create(VideoMode(720, 900), "Hello SFML");
	window.setFramerateLimit(60);

	font.loadFromFile("arial.ttf");

	text.setFont(font);
	text.setFillColor(Color::Black);
	text.setPosition(5.0f, 0.0f);
	text.setCharacterSize(30);

	Level.setFont(font);
	Level.setFillColor(Color::Black);
	Level.setPosition(370.0f, 0.0f);
	Level.setCharacterSize(30);

	Level1.setFont(font);
	Level1.setFillColor(Color::Black);
	Level1.setPosition(280.0f, 0.0f);
	Level1.setCharacterSize(30);
}

void Engine::loop(){
	while (window.isOpen()){
		while (window.pollEvent(event)){
			switch (event.type){
			case Event::Closed:
				window.close();
				break;
			default:
				break;
			}
		}
		indi.moveIndi();
		render();

		if (indi.life.size() <= 0)
			GameOver();
		else if (cur_score / 10 > level) {
			ddongs.levelUp();
			level++;
		}
	}
}

void Engine::render()
{
	ddongs.update(score);
	indi.update(ddongs, score, s);

	window.clear(Color::White);
	indi.draw(window);
	ddongs.draw(window);
	cur_score = score.update();
	text.setString(to_string(cur_score));
	Level.setString(to_string(level));
	Level1.setString(string("Level: "));

	window.draw(text);
	window.draw(Level);
	window.draw(Level1);
	window.display();
}

void Engine::GameOver()
{
	while (1) {
		window.clear(Color::Black);
		Level1.setFillColor(Color::White);
		Level.setFillColor(Color::White);

		Level1.setPosition(250.0f, 400.0f);
		Level1.setCharacterSize(40);
		Level1.setString(string("Game Over!"));
		window.draw(Level1);

		Level1.setCharacterSize(15);
		Level1.setPosition(290.0f, 470.0f);
		Level1.setString(string("Press ESC to Exit..."));
		window.draw(Level1);

		Level1.setCharacterSize(20);
		Level1.setPosition(280.0f, 370.0f);
		Level1.setString(string("Your Score: "));
		window.draw(Level1);

		Level.setCharacterSize(20);
		Level.setPosition(400.0f, 370.0f);
		Level.setString(to_string(score.update()));
		window.draw(Level);

		window.display();
		if (window.waitEvent(event) == Keyboard::isKeyPressed(Keyboard::Escape)) {
			window.close();
			break;
		}
	}
}
