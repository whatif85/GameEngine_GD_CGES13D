#include "Engine.h"


Engine::Engine(){}

Engine::~Engine(){}

void Engine::Update()
{
	sf::Event _event;

	while (window->pollEvent(_event))
	{
		// "close requested" event: we close the window
		if (_event.type == sf::Event::Closed)
		{
			window->close();
		}
	}
}

Engine& Engine::GetInstance()
{
	static Engine _instance;

	return _instance;
}

void Engine::Start(sf::RenderWindow* win)
{
	bIsQuit = false;
	window = win;

	// Run the program as long as the window is open
	while (window->isOpen())
	{
		Update();
	}
}
