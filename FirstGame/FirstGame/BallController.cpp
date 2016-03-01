#include "BallController.h"

BallController::BallController(GameObject* owner)
	: Component(owner, Component::getDefaultProperties())
{

}

void BallController::update(float deltaTime)
{
	// Set movespeed for the ball
	// Tiles / second
	float moveSpeed = 1.0f;
	float velocity = 0.001f;
	
	// 
	vec2 direction;
	if (getKeyState(KEY_SPACE) && !movement)
	{
		movement = true;
	}

	if (movement == true)
	{
		getGameObject()->setPosition(getGameObject()->getPosition() + deltaTime*moveSpeed*vec2(1.0f, -1.0f));

	}
	
}

BallController::~BallController()
{

}