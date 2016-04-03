#pragma once

#include "SpriteComponent.h"
#include "GameObject.h"
#include "Input.h"

using namespace yam2d;

class Paddle1Controller : public Component, public Updatable
{
public:
	Paddle1Controller(GameObject* parent);
	virtual~Paddle1Controller();

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