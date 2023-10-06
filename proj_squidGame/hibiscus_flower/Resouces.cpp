#include"Resources.h"

map<int, Sprite*> Resources::sprites;
map<int, Animation> Resources::animations;

const int Resources::Player = 0;
const int Resources::NPC_1 = 1;
const int Resources::NPC_2 = 2;
const int Resources::NPC_3 = 3;
const int Resources::NPC_4 = 4;
const int Resources::NPC_5 = 5;
const int Resources::Tagger = 6;
const int Resources::TaggerBack = 7;
const int Resources::Boom = 8;


void Resources::load()
{
	people.loadFromFile("images/people.png");
	loadSprite(Player, 0, 0, 8);
	loadSprite(NPC_1, 0, 100, 7);
	loadSprite(NPC_2, 0, 100, 7);
	loadSprite(NPC_3, 0, 100, 7);
	loadSprite(NPC_4, 0, 100, 7);
	loadSprite(NPC_5, 0, 100, 7);
	loadSprite(Tagger, 0, 200, 5);
	loadSprite(TaggerBack, 0, 400, 5);

	boom.loadFromFile("images/boom.png");
	loadSprite(Boom, 0, 0, 6);
}

void Resources::loadSprite(int value, int rect1, int rect2, int animationframes)
{
	Sprite* sprite;
	IntRect* rect;
	if (value == 8)
	{
		rect = new IntRect(rect1, rect2, 200, 300);
		sprite = new Sprite(boom, *rect);
		
	}
	else
	{
		if (value <= 5)
		{
			rect = new IntRect(rect1, rect2, 70, 100);
		}
		else
		{
			rect = new IntRect(rect1, rect2, 70, 200);
		}
		sprite = new Sprite(people, *rect);
	}
	sprites.insert(pair<int, Sprite*>(value, sprite));
	animations.insert(pair<int, Animation>(value, Animation(rect, animationframes)));
}

Sprite* Resources::get(int value, bool animated, float _speed)
{
	if (animated)
	{
		animations.at(value).changeFrame(_speed);
		sprites.at(value)->setTextureRect(animations.at(value).getBounds());
	}
	return sprites.at(value);
}

Sprite* Resources::getBoom()
{
	animations.at(Boom).changeBoomFrame(0.2f);
	sprites.at(Boom)->setTextureRect(animations.at(8).getBounds());
	return sprites.at(Boom);
}