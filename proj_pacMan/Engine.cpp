#include "Engine.h"

#include "PlayingState.h"
#include "Resources.h"

using namespace sf;

StateManager Engine::gamestates;

void Engine::init(Resources& _r)
{
	_r.load();
	window.create(VideoMode(448, 596), "PacMan Game");
	gamestates.addState(new PlayingState);
}

bool Engine::isRunning()
{
	return window.isOpen();
}

void Engine::handleEvents()
{
	Event event;
	while (window.pollEvent(event))
	{
		switch (event.type)
		{
		case Event::Closed:
			window.close();
			break;
		case Event::KeyPressed:
			gamestates.keyPressed(event.key.code);
			break;
		case Event::KeyReleased:
			gamestates.keyReleased(event.key.code);
			break;
		}
	}
	gamestates.loop();
}

void Engine::render()
{
	window.clear(Color::Black);
	gamestates.render(&window);
	window.display();
}
