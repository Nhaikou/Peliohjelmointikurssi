#pragma once
#include "GameState.h"
#include "MainMenuState.h"
#include "PongGameComponents.h"
#include "TextComponent.h"
#include <iostream>
#include <string>

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
	Ref<PongGameComponents> m_pongComponents;
	Ref<GameObject> m_scoreFont1, m_scoreFont2;
	size_t m_score1, m_score2 = 0;


};

