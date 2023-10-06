#pragma once
#include<SFML/Audio.hpp>

using namespace sf;

class Tagger
{
private:
	SoundBuffer buffer[7];
	Sound song;

	Clock t_clock;
	Time time;
	int playingWhat;

public:
	Sound detect;
	Sound explosion;
	int cnt = 0;

	Tagger();
	void play();
	bool isSinging();
	bool isDetecting();
};