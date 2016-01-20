#pragma once
#include "Object.h"
#include <es_util.h>
#include "GameApp.h"
class GameState : yam2d::Object
{
public:
	
	virtual bool update(yam2d::ESContext* ctx, float deltaTime);
	virtual void Render(yam2d::ESContext* ctx);
	GameApp* getApp();

protected:
	GameApp* m_gameApp;
};

