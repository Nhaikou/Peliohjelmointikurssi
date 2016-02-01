#pragma once
#include "Object.h"
#include "es_util.h"
#include "Ref.h"
#include "Map.h"
#include "Input.h"
#include "SpriteBatch.h"
#include "Sprite.h"
#include "Text.h"
#include "SpriteSheet.h"
#include "Texture.h"
#include "GameApp.h"

class GameApp;

using namespace yam2d;

class GameState : public Object
{

public:
	
	GameState(GameApp* app) : Object(), m_app(app)
	{

	}
	virtual~GameState(){}

	virtual bool update(ESContext* ctx, float deltaTime)
	{
		assert(m_app != 0);
		return true;
	}
	virtual void render(ESContext* ctx)
	{

	}

	GameApp* getApp()
	{
		return m_app;
	};

private:
	GameApp* m_app;
};

