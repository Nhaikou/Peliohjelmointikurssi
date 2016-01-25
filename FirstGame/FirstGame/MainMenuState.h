#pragma once
#include "GameState.h"

class MainMenuState : public GameState
{
public:
	MainMenuState();
	virtual~MainMenuState();

	virtual bool update(ESContext* ctx, float deltaTime);
	virtual void render(ESContext* ctx);

private:
	Ref<yam2d::Map> m_map;
};

