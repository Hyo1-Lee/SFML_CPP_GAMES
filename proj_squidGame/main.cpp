#include"GameEngine.h"

int main()
{
	srand((unsigned int)time(NULL));

	GameEngine gameengine;
	gameengine.loop();

	return 0;
}