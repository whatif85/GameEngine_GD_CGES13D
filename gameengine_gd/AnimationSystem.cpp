#include "include\AnimationSystem.h"


AnimationSystem::AnimationSystem()
{
}

AnimationSystem::~AnimationSystem()
{
}

void AnimationSystem::tick(ECS::World* world, float deltaTime)
{
	// normal function call
	// MyClass myObject;
	// myObject.MyFunction();

	// lambda function call in .cpp function
	// MyFunction<MyOtherClass>(([&]myParams) -> returntype
	// {
	// });

	world->each<Animator, Sprite2D>(
		[&](ECS::Entity* entity,
			ECS::ComponentHandle<Animator> animator,
			ECS::ComponentHandle<Sprite2D> sprite
			) -> void
	{
		// TODO: shouldn't it be using .?
			animator->currentTime += deltaTime;

			if (animator->currentTime >= animator->nextFrameTime)
			{
				animator->currentTime = 0;
				animator->currentColumn = (animator->currentColumn + 1) % 4; // TODO: Hardcoded value
			}

			sprite->Image.setTextureRect(
				sf::IntRect(animator->currentColumn * animator->spriteWidth,
							animator->currentRow * animator->spriteHeight,
							animator->spriteWidth,
							animator->spriteHeight));
	});
}
