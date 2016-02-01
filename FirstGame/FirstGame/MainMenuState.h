#pragma once
#include "es_util.h"
#include "GameState.h"
#include "Map.h"
#include "Input.h"
#include "TileComponent.h"
#include "SpriteComponent.h"
#include "Layer.h"
#include "Camera.h"
#include <iostream>

class MainMenuState : public GameState
{
public:
	MainMenuState(GameApp* app);
	virtual~MainMenuState();

	virtual bool update(ESContext* ctx, float deltaTime);
	virtual void render(ESContext* ctx);

	GameObject* createSpriteGameObject(const std::string& bitmapFileName, float sizeX, float sizeY, bool isWhiteTransparentColor);
	GameObject* createSpriteGameObject(const std::string& bitmapFileName, float sizeX, float sizeY, int clipStartX, int clipStartY, int clipSizeX, int clipSizeY, bool isWhiteTransparentColor);

private:
	GameApp* m_app;
	Ref<Map> m_map;
};

