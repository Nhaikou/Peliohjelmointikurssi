#pragma once
#include "GameState.h"
#include "Map.h"
#include "Input.h"

class MainMenuState : public GameState
{
public:
	MainMenuState(GameApp* app);
	virtual~MainMenuState();

	virtual bool update(ESContext* ctx, float deltaTime);
	virtual void render(ESContext* ctx);

private:
	GameApp* m_app;
	Ref<Map> m_map;
};

