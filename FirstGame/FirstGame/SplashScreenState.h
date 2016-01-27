#pragma once
#include "GameState.h"
#include "MainMenuState.h"

class SplashScreenState : public GameState
{
public:
	SplashScreenState(GameApp* app);
	virtual~SplashScreenState();
	
	virtual bool update(ESContext* ctx, float deltaTime);
	virtual void render(ESContext* ctx);

private:
	float m_totalTime;
	GameApp* m_app;
	Ref<Sprite> m_sprite;
};

