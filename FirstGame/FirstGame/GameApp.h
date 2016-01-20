#pragma once
#include <Object.h>
#include <es_util.h>
#include <Ref.h>
class GameApp : yam2d::Object
{
public:
	bool update(yam2d::ESContext* ctx, float deltaTime);
	void render(yam2d::ESContext* ctx);
	void setState(GameState* newState);
protected:
	yam2d::Ref<GameState> m_currentState;
};

