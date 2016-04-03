#pragma once
#include "GameState.h"
#include "MainMenuState.h"
#include "PongGameComponents.h"

class GameRunningState2 : public GameState
{
public:
	GameRunningState2(GameApp* app);
	virtual~GameRunningState2();

	virtual bool update(ESContext* ctx, float deltaTime);
	virtual void render(ESContext* ctx);
	float getZoom();
	void setZoom(float newZoom);

private:
	float deltaTime = 0;
	float zoom = 1.0f;
	Ref<GameObject> m_gameObject;
	Ref<TmxMap> m_tmap;
	float mouseX = 0.0f;
	float mouseY = 0.0f;
	PongGameComponents *m_pongComponents;

};

