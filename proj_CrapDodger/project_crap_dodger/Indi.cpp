#include "Indi.h"

Indi::Indi(){
	tt.loadFromFile("indi.png");
	indi.setTexture(tt);
	indi.setPosition(360.0f, 900.0f - 60.0f);

	t.loadFromFile("heart.png");
	for (int i = 0; i < 3; i++){
		Sprite heart;
		heart.setTexture(t);
		heart.setPosition(680.0f - (float)i * 25.0f, 10.0f);
		life.push_back(heart);
	}

	hitted = false;
	hit_time = 0;
	speed = 5.0f;
}

void Indi::moveIndi(){
	if (Keyboard::isKeyPressed(Keyboard::Left) and indi.getPosition().x >= 0.0f)
		indi.move(-speed, 0);

	else if (Keyboard::isKeyPressed(Keyboard::Right) and indi.getPosition().x <= 720.0f - 40.0f)
		indi.move(speed, 0);

	if (Keyboard::isKeyPressed(Keyboard::Space) and indi.getPosition().y >= 840.0f)
	{
		jumpFlag = true;
	}

	if (jumpFlag)
	{
		if (flag)
		{
			indi.move(0.0f, -3.0f);
			if (indi.getPosition().y <= 750.0f) flag = false;
		}
		else
		{
			indi.move(0.0f, 3.0f);
			if (indi.getPosition().y >= 840.0f) {
				flag = true;
				jumpFlag = false;
			}
		}
	}
}

void Indi::update(Ddong_GEN& ddongs, Score& score, soundEffect& s)
{
	indi.setColor(Color::White);
	if (ddongs.checkHit(indi.getGlobalBounds()) == true) {
		life.pop_back();
		s.playSound();
		indi.setColor(Color::Red);
	}
	
}

void Indi::draw(RenderWindow& _window)
{
	for (int i = 0; i < life.size(); i++)
	{
		_window.draw(life.at(i));
	}
	_window.draw(indi);
}