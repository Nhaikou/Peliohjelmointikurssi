#include "PlayerController.h"

PlayerController::PlayerController(GameObject* owner) : Component(owner, Component::getDefaultProperties())
{
}

PlayerController::~PlayerController(void)
{
}

void PlayerController::update(float deltaTime)
{
	float moveSpeed = 4.0f;	//Tiles / second

	// Get move direction from keyboard
	
	float right = float(getKeyState(KEY_RIGHT) - getKeyState(KEY_LEFT));
	float left = float(getKeyState(KEY_LEFT) - getKeyState(KEY_RIGHT));

	if (fabsf(right)>0.1f)
	{
		vec2 direction;

		direction = slm::normalize(direction);

		// Update position
		getGameObject()->setPosition(getGameObject()->getPosition() + deltaTime*moveSpeed*direction);
	}
	else if (fabsf(left)>-0.1f)
	{
		vec2 direction;

		direction = slm::normalize(direction);

		// Update position
		getGameObject()->setPosition(getGameObject()->getPosition() - deltaTime*moveSpeed*direction);
	}
}