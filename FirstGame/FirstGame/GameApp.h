#pragma once
#include "Object.h"
#include "es_util.h"
#include "Ref.h"
#include "GameState.h"

using namespace yam2d;

class GameState;

class GameApp : public Object
{
public:
	GameApp();
	virtual~GameApp();

	bool update(ESContext* ctx, float deltaTime);
	void render(ESContext* ctx);
	void setState(GameState* newState);
protected:
	Ref<GameState> m_currentState;
};

