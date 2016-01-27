#include "MainMenuState.h"


MainMenuState::MainMenuState(GameApp* app) : GameState(app), m_app(app)
{
}


MainMenuState::~MainMenuState()
{
}


bool MainMenuState::update(ESContext* ctx, float deltaTime)
{
	return true;
}

void MainMenuState::render(ESContext* ctx)
{
	
}