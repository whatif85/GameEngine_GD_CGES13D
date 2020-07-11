// Game Main

#include <SFML\Graphics.hpp>
#include "..\GameEngine_GD\include\Engine.h"


int main(int argc, char* args[])
{
	// Declare and get instance of singleton
	Engine& gameEngine = Engine::GetInstance();

	sf::RenderWindow window(sf::VideoMode(800, 600), "Game Engine");

	// Create world for attaching entities and system to
	gameEngine.world = ECS::World::createWorld();
	ECS::Entity* background;
	ECS::Entity* guy;

	// Add the systems to the engine
	gameEngine.AddSystem(new RenderingSystem());
	gameEngine.AddSystem(new AnimationSystem());

	background = gameEngine.world->create();
	guy = gameEngine.world->create();

	// Assign components to entities after creation
	background->assign<Transform>(0, 0);
	background->assign<Sprite2D>("../Debug/Images/bg.jpg");

	guy->assign<Transform>(100, 100);
	guy->assign<Sprite2D>("../Debug/Images/herosheet.png");
	guy->assign<Animator>(32, 32, 1400.0f);

	std::cout << background->getEntityId() << " is the entity ID." << std::endl;
	std::cout << guy->getEntityId() << " is the entity ID." << std::endl;

	// Pass the window's reference to the engine and start
	gameEngine.Start(&window);

	return 0;
}