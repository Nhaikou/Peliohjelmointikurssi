#include "GameRunningState2.h"

GameRunningState2::GameRunningState2(GameApp* app)
	: GameState(app)
	, m_tmap(0)
	, m_gameObject(0)
	, m_pongComponents(0)
	, m_score1(0)
	, m_score2(0)
{
	esLogMessage("Initializing secret level!");
	m_tmap = new TmxMap();
	m_pongComponents = new PongGameComponents(m_tmap);

	bool load = m_tmap->loadMapFile("assets/level_pong.tmx", m_pongComponents);
	
	if (load)
	{
		m_tmap->getCamera()->setPosition(vec2(m_tmap->getWidth()/2.22f, m_tmap->getHeight()/2.2f));
	}

	m_scoreFont1 = static_cast<GameObject*>(m_pongComponents->createNewEntity(m_pongComponents, "Score", nullptr, PropertySet()));
	m_scoreFont2 = static_cast<GameObject*>(m_pongComponents->createNewEntity(m_pongComponents, "Score", nullptr, PropertySet()));
}

bool GameRunningState2::update(ESContext* ctx, float deltaTime)
{
	if (getKeyState(KEY_ESCAPE) == 1)
	{
		getApp()->setState(new MainMenuState(getApp()));
		return true;
	}

	// Collision checks
	slm::vec2 plaa = slm::vec2(0.0f);
	for (int i = 0; i < m_tmap->getLayer("StaticColliders")->getGameObjects().size(); i++)
	{
		if (m_tmap->findGameObjectByName("Ball")->collidesTo(m_tmap->getLayer("StaticColliders")->getGameObjects()[i], &plaa))
		{
			m_tmap->findGameObjectByName("Ball")->getComponent<BallController2>()->collisionCheck(m_tmap->getLayer("StaticColliders")->getGameObjects()[i], deltaTime);
		}
	}
	for (int i = 0; i < m_tmap->getLayer("DynamicObjects")->getGameObjects().size(); i++)
	{
		if (m_tmap->findGameObjectByName("Ball")->collidesTo(m_tmap->getLayer("DynamicObjects")->getGameObjects()[i], &plaa))
		{
			m_tmap->findGameObjectByName("Ball")->getComponent<BallController2>()->collisionCheck(m_tmap->getLayer("DynamicObjects")->getGameObjects()[i], deltaTime);
		}
	}

	m_tmap->update(deltaTime);
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
}