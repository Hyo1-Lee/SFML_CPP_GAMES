#include"Tagger.h"

Tagger::Tagger()
{
	buffer[0].loadFromFile("sounds/sound_1.wav");
	buffer[1].loadFromFile("sounds/sound_2.wav");
	buffer[2].loadFromFile("sounds/sound_3.wav");
	buffer[3].loadFromFile("sounds/sound_4.wav");
	buffer[4].loadFromFile("sounds/sound_5.wav");
	buffer[5].loadFromFile("sounds/detect.wav");
	buffer[6].loadFromFile("sounds/explosion.wav");

	detect.setBuffer(buffer[5]);
	explosion.setBuffer(buffer[6]);
}

void Tagger::play()
{
	playingWhat = rand() % 5;
	song.setBuffer(buffer[playingWhat]);
	song.play();
	t_clock.restart();
}

bool Tagger::isSinging()
{
	if (song.getStatus() == SoundSource::Status::Playing) return true;
	return false;
}

bool Tagger::isDetecting()
{
	time = t_clock.getElapsedTime();
	if (time.asSeconds() <= buffer[playingWhat].getDuration().asSeconds() 
		+ buffer[5].getDuration().asSeconds() + 0.5f and song.getStatus() != SoundSource::Status::Playing)
	{
		return true;
	}
	return false;
}