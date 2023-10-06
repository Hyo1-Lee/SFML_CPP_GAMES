#include "Engine.h"

int main()
{
	srand((unsigned int)time(NULL));

	Engine engine;
	engine.loop();

	return 0;
}