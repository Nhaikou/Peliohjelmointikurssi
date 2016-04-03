#pragma once

#include "SpriteComponent.h"
#include "GameObject.h"
#include "Input.h"

using namespace yam2d;

class Paddle2Controller : public Component, public Updatable
{
public:
	Paddle2Controller(GameObject* parent);
	virtual~Paddle2Controller();

	virtual void update(float deltaTime);

	GameObject* getGameObject()
	{
		return (GameObject*)getOwner();
	}
	const GameObject* getGameObject() const
	{
		return (const GameObject*)getOwner();
	}

private:

};