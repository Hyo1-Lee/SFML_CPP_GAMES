#include"playSound.h"

void playSound::setNote(int _n) {
	for (int i = 0; i < 44100; i++) {
		samples[i] = ((5000 * sin(notes[_n] * (2.0f*3.14f) * i / 44100)));
	}
	buffer.loadFromSamples(samples, 44100, 1, 44100);
	sound.setBuffer(buffer);
}

void playSound::on() {
	sound.play();
}

void playSound::off() {
	sound.stop();
}
