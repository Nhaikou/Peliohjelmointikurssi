#include "BallController2.h"
#define PI 3.1415;

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
	float angle = slm::radians(rand() % 90 + 315);
	direction.x = cosf(angle);
	direction.y = sinf(angle);

	if ((rand() % 100) < 50)
		direction.x *= -1;

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
		getGameObject()->setPosition(getGameObject()->getPosition() + deltaTime*moveSpeed*direction*position);
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
	// DynamicObject colliders are "PlayerPad1" and "PlayerPad2"
	if (movement)
	{
		if (objects->getName() == "Left" || objects->getName() == "Right")
		{
			movement = false;
			moveSpeed = 1.0f;

			float angle = slm::radians(rand() % 90 + 315);
			direction.x = cosf(angle);
			direction.y = sinf(angle);

			if ((rand() % 100) < 50)
				direction.x *= -1;

			return getGameObject()->setPosition(9, 6);
		}

		if (objects->getName() == "Top" || objects->getName() == "Bottom")
		{
			position.y *= -1.0f;
		}

		if (objects->getName() == "PlayerPad1" || objects->getName() == "PlayerPad2")
		{
			float angle = 0.0f;
			
			if(direction.x > 0)
				angle = slm::radians(rand() % 90 + 135);
			else
				angle = slm::radians(rand() % 90 + 315);

			direction.x = cosf(angle);
			direction.y = sinf(angle);

			moveSpeed *= 1.08f;	// Movespeed is increased.
		}
	}
}

BallController2::~BallController2()
{

}