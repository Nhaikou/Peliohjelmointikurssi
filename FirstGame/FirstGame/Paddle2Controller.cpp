#include "Paddle2Controller.h"

Paddle2Controller::Paddle2Controller(GameObject* owner)
	: Component(owner, Component::getDefaultProperties())
{
}

Paddle2Controller::~Paddle2Controller(void)
{
}

void Paddle2Controller::update(float deltaTime)
{
	float moveSpeed = 8.0f;	//Tiles / second
	vec2 direction;
	// Get move direction from keyboard

	// Position is counted by the size of 1 block e.g. (64 x 1.0f) 
	if (getKeyState(KEY_UP) && getGameObject()->getPosition().y>2.0f)
	{
		getGameObject()->setPosition(getGameObject()->getPosition() + deltaTime*moveSpeed*vec2(0.0f, -1.0f));
	}
	if (getKeyState(KEY_DOWN) && getGameObject()->getPosition().y<9.0f)
	{
		getGameObject()->setPosition(getGameObject()->getPosition() + deltaTime*moveSpeed*vec2(0.0f, 1.0f));
	}
}