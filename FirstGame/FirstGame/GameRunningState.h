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
	GameObject* createSpriteGameObject(const std::string& bitmapFileName, float sizeX, float sizeY, int clipStartX, int clipStartY, int clipSizeX, int clipSizeY, bool isWhiteTransparentColor);
	
private:
	float deltaTime = 0;
	float zoom = 1.0f;
	Ref<TmxMap> m_tmap;
	MyGameComponentFactory* m_componentFactory;
};

