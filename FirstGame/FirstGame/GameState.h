#pragma once
#include "Object.h"
#include <es_util.h>
#include "Sprite.h"
#include "Map.h"
#include "Input.h"

class GameApp;
using namespace yam2d;

class GameState : public Object
{
public:
	GameState();
	virtual~GameState();

	virtual bool update(ESContext* ctx, float deltaTime);
	virtual void render(ESContext* ctx);
	
	GameApp* getApp();

protected:
	GameApp* m_gameApp;
};

