#include "BallController.h"

BallController::BallController(GameObject* owner)
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

void BallController::update(float deltaTime)
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
		return getGameObject()->setPosition(9,10); // Positions are 64x64 tiels
	}
	
}

void BallController::collisionCheck(GameObject* objects, float deltaTime)
{
	// StaticCollider walls are "TopWall", "LeftWall", "RightWall" and "Bottom"

	if (movement)
	{
		if (objects->getName() == "LeftWall" || objects->getName() == "RightWall")
		{
			position.x *= -1.0f;
		}

		if (objects->getName() == "TopWall")
		{
			position.y *= -1.0f;
		}
		if (objects->getName() == "Bottom")
		{
			movement = false;
		}

		if (objects->getName() == "PlayerPad")
		{
			position.y *= -1.0f;
		}
	}
}

BallController::~BallController()
{

}