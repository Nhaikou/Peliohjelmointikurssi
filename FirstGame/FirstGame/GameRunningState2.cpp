#include "GameRunningState2.h"

GameRunningState2::GameRunningState2(GameApp* app) : GameState(app), m_tmap(0), m_gameObject(0)
{
	esLogMessage("Initializing secret level!");
	m_tmap = new TmxMap();

}

bool GameRunningState2::update(ESContext* ctx, float deltaTime)
{
	if (getKeyState(KEY_ESCAPE) == 1)
	{
		getApp()->setState(new MainMenuState(getApp()));
		return true;
	}
	return true;
}

void GameRunningState2::render(ESContext* ctx)
{
	// Set OpenGL clear color
	glClearColor(0.3f, 0.3f, 0.3f, 1.0f);

	// Clear the color buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

GameRunningState2::~GameRunningState2()
{
	// Delete your game content
	esLogMessage("Deinit");
}