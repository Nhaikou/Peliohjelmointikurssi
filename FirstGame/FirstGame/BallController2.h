#pragma once

#include "SpriteComponent.h"
#include "GameObject.h"
#include "Input.h"
#include <iostream>
using namespace yam2d;

class BallController2 : public Component, public Updatable
{
public:
	BallController2(GameObject* parent);
	virtual~BallController2();

	virtual void update(float deltaTime);

	GameObject* getGameObject()
	{
		return (GameObject*)getOwner();
	}
	const GameObject* getGameObject() const
	{
		return (const GameObject*)getOwner();
	}

	void collisionCheck(GameObject* objects, float deltaTime);

	void setPositionToMouse(slm::vec2 posMouse){ getGameObject()->setPosition(posMouse); }

private:
	bool movement;
	float moveSpeed;
	float velocity;
	vec2 direction;
	vec2 position;
	float positionX;
	float positionY;
};