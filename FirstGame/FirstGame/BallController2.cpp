#include "BallController2.h"

BallController2::BallController2(GameObject* owner)
	: Component(owner, Component::getDefaultProperties())
{

	movement = false;
	// Set movespeed for the ball
	// Tiles / second
	moveSpeed = 1.0f;
	velocity = 0.001f;

	// Ball position
	positionX = 3.0f;
	positionY = -1.0f;

	//
	direction;
	position = vec2(positionX, positionY);
}

void BallController2::update(float deltaTime)
{
	if (getKeyState(KEY_SPACE) && !movement)
	{
		movement = true;
	}

	if (movement == true)
	{
		getGameObject()->setPosition(getGameObject()->getPosition() + deltaTime*moveSpeed*position);
	}

	// Returns ball position where it was first
	if (getKeyState(KEY_RETURN))
	{
		movement = false;
		position = vec2(positionX, positionY);
		// Returns ball position in the middle
		return getGameObject()->setPosition(9, 6); // Positions are 64x64 tiels
	}

}

void BallController2::collisionCheck(GameObject* objects, float deltaTime)
{
	// StaticCollider walls are "Top", "Left", "Right" and "Bottom"
	if (movement)
	{
		if (objects->getName() == "Left" || objects->getName() == "Right")
		{
			movement = false;
			return getGameObject()->setPosition(9, 6);
		}

		if (objects->getName() == "Top" || objects->getName() == "Bottom")
		{
			position.y *= -1.0f;
		}

		if (objects->getName() == "PlayerPad1" || objects->getName() == "PlayerPad2")
		{
			position.x *= -1.0f;
			moveSpeed *= 1.2f;		// TODO: FIX VELOCITY
		}
	}
}

BallController2::~BallController2()
{

}