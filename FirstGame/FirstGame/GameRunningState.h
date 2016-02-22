#pragma once
#include "GameState.h"
#include "MainMenuState.h"
#include "MyGameComponentFactory.h"

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
	float zoom = 1.0f;
	Ref<GameObject> m_gameObject;
	Ref<TmxMap> m_tmap;
	MyGameComponentFactory* m_componentFactory;
};

