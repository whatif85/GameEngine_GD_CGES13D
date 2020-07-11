#pragma once

#include "ECS.h"
#include "Engine.h"
#include "Components.h"


class AnimationSystem : public ECS::EntitySystem
{
private:

	void tick(ECS::World* world, float deltaTime) override;

public:
	AnimationSystem(void);
	~AnimationSystem(void);
};

