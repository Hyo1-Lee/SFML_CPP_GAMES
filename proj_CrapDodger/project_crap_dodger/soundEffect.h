#pragma once
#include<SFML/Audio.hpp>
#include <iostream>

using namespace sf;
using namespace std;

class soundEffect {
public:
	SoundBuffer buffer;
	Sound sound;
	soundEffect();
	void playSound();
};