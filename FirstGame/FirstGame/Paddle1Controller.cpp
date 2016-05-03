#include "Paddle1Controller.h"

Paddle1Controller::Paddle1Controller(GameObject* owner)
	: Component(owner, Component::getDefaultProperties())
{
}

Paddle1Controller::~Paddle1Controller(void)
{
}

void Paddle1Controller::update(float deltaTime)
{
	float moveSpeed = 4.0f;	//Tiles / second
	vec2 direction;
	// Get move direction from keyboard

	// Position is counted by the size of 1 block e.g. (64 x 1.0f) 
	if (getKeyState(KEY_W) && getGameObject()->getPosition().y>2.0f)
	{
		getGameObject()->setPosition(getGameObject()->getPosition() + deltaTime*moveSpeed*vec2(0.0f, -1.0f));
	}
	if (getKeyState(KEY_S) && getGameObject()->getPosition().y<9.0f)
	{
		getGameObject()->setPosition(getGameObject()->getPosition() + deltaTime*moveSpeed*vec2(0.0f, 1.0f));
	}
}