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
	assert(m_currentState != 0);
	return m_currentState->update(ctx, deltaTime);
}

void GameApp::render(ESContext* ctx)
{
	assert(m_currentState != 0);
	m_currentState->render(ctx);
}

void GameApp::setState(GameState* newState)
{
	m_currentState = newState;
}
