#pragma once
#include "GameState.h"

class SplashScreenState : public GameState
{
public:
	SplashScreenState();
	virtual~SplashScreenState();
	
	virtual bool update(ESContext* ctx, float deltaTime);
	virtual void render(ESContext* ctx);

private:
	Ref<yam2d::Sprite> m_sprite;
};

