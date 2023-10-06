#pragma once
#include<SFML/Audio.hpp>

using namespace std;
using namespace sf;

class playSound {
private:
	Int16 samples[44100];
	Int16 notes[10] = { 261, 293, 329, 349, 391, 440, 493, 523, 587, 659 };
	SoundBuffer buffer;
	Sound sound;
public:
	
	void setNote(int _n);
	void on();
	void off();
};