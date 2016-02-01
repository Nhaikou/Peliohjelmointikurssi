#include "GameApp.h"


GameApp::GameApp() : Object(), m_currentState(0)
{
}


GameApp::~GameApp()
{
	delete m_currentState;
}

bool GameApp::update(ESContext* ctx, float deltaTime)
{
	return m_currentState->update(ctx, deltaTime);
	return true;
}

void GameApp::render(ESContext* ctx)
{
	m_currentState->render(ctx);
}

void GameApp::setState(GameState* newState)
{
	m_currentState = newState;
}
