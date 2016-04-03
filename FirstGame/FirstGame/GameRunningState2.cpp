#include "GameRunningState2.h"

GameRunningState2::GameRunningState2(GameApp* app) : GameState(app), m_tmap(0), m_gameObject(0), m_componentFactory(0)
{
	esLogMessage("Initializing secret level!");
	m_tmap = new TmxMap();
	m_componentFactory = new DefaultComponentFactory();

	bool load = m_tmap->loadMapFile("assets/level_pong.tmx", m_componentFactory);
	
	if (load)
	{
		m_tmap->getCamera()->setPosition(vec2(m_tmap->getWidth()/2.22f, m_tmap->getHeight()/2.2f));
	}

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

	// Screen size to camera
	m_tmap->getCamera()->setScreenSize(ctx->width, ctx->height);

	// Render map and all of its layers containing GameObjects to screen.
	m_tmap->render();
}

GameRunningState2::~GameRunningState2()
{
	// Delete your game content
	esLogMessage("Deinit");
	delete m_componentFactory;
}