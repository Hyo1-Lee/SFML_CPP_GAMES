#include "soundEffect.h"

using namespace sf;
using namespace std;

soundEffect::soundEffect() {
	if (!buffer.loadFromFile("car-door-closewav-6929.wav")) {
		cout << "error" << endl;
	}
	sound.setBuffer(buffer);
}

void soundEffect::playSound() {
	sound.play();
}