#pragma once
#include<map>
#include"Animation.h"

using namespace std;
using namespace sf;

class Resources
{
private:
	Texture people;
	Texture boom;
	static map<int, Sprite*> sprites;
	static map<int, Animation> animations;
public:
	void loadSprite(int value, int rect1, int rect2, int animationframes);
	void load();
	static Sprite* get(int value, bool animated, float _speed);
	static Sprite* getBoom();

	static const int Player;
	static const int NPC_1;
	static const int NPC_2;
	static const int NPC_3;
	static const int NPC_4;
	static const int NPC_5;
	static const int Tagger;
	static const int TaggerBack;
	static const int Boom;
};