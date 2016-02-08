#pragma once
#include "GameState.h"
#include "MainMenuState.h"
#include <iostream>

class GameRunningState : public GameState
{
public:
	GameRunningState(GameApp* app);
	virtual~GameRunningState();

	virtual bool update(ESContext* ctx, float deltaTime);
	virtual void render(ESContext* ctx);
	float getZoom();
	void setZoom(float newZoom);
	void moveGameObject(GameObject paddle, float speed, float deltatime, bool moveDirection);
	GameObject* createSpriteGameObject(const std::string& bitmapFileName, float sizeX, float sizeY, int clipStartX, int clipStartY, int clipSizeX, int clipSizeY, bool isWhiteTransparentColor);

private:
	float deltaTime = 0;
	TmxMap* m_tmap = 0;
	ComponentFactory* m_componentFactory = 0;
	float zoom = 1.0f;
	GameObject* m_paddle;
	Ref<Layer> objectsLayer;
};

