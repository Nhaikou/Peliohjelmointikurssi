#pragma once
#include "GameState.h"
#include "MainMenuState.h"

class GameRunningState : public GameState
{
public:
	GameRunningState(GameApp* app);
	virtual~GameRunningState();

	virtual bool update(ESContext* ctx, float deltaTime);
	virtual void render(ESContext* ctx);
	float getZoom();
	void setZoom(float newZoom);

private:
	float deltaTime = 0;
	TmxMap* map = 0;
	ComponentFactory* componentFactory = 0;
	float zoom = 1.0f;
};

