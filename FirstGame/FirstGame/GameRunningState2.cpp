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

	// Player 1 score
	m_scoreFont1 = static_cast<GameObject*>(m_pongComponents->createNewEntity(m_pongComponents, "Score", nullptr, PropertySet()));
	m_scoreFont1->getComponent<TextComponent>()->getText()->setText(std::to_string(m_score1));
	m_scoreFont1->getComponent<TextComponent>()->getText()->setColor(255, 255, 255, 1);
	m_scoreFont1->setSize(vec2(64.0f, 64.0f) * 20.0f);
	m_scoreFont1->setPosition(7.0f, 6.0f);
	
	// Player 2 score
	m_scoreFont2 = static_cast<GameObject*>(m_pongComponents->createNewEntity(m_pongComponents, "Score", nullptr, PropertySet()));
	m_scoreFont2->getComponent<TextComponent>()->getText()->setText(std::to_string(m_score2));
	m_scoreFont2->getComponent<TextComponent>()->getText()->setColor(255, 255, 255, 1);
	m_scoreFont2->setSize(vec2(64.0f, 64.0f) * 20.0f);
	m_scoreFont2->setPosition(15.0f, 6.0f);

	// You only need 5 points to win

	// Player 1 win text
	m_p1Win = static_cast<GameObject*>(m_pongComponents->createNewEntity(m_pongComponents, "Score", nullptr, PropertySet()));
	
	// Player 2 win text
	m_p2Win = static_cast<GameObject*>(m_pongComponents->createNewEntity(m_pongComponents, "Score", nullptr, PropertySet()));
}

bool GameRunningState2::update(ESContext* ctx, float deltaTime)
{
	if (getKeyState(KEY_ESCAPE) == 1)
	{
		getApp()->setState(new MainMenuState(getApp()));
		return true;
	}

	// Collision checks
	slm::vec2 check = slm::vec2(0.0f);
	for (int i = 0; i < m_tmap->getLayer("StaticColliders")->getGameObjects().size(); i++)
	{
		if (m_tmap->findGameObjectByName("Ball")->collidesTo(m_tmap->getLayer("StaticColliders")->getGameObjects()[i], &check))
		{
			m_tmap->findGameObjectByName("Ball")->getComponent<BallController2>()->collisionCheck(m_tmap->getLayer("StaticColliders")->getGameObjects()[i], deltaTime);
			if ("Right" == m_tmap->getLayer("StaticColliders")->getGameObjects()[i]->getName())
			{
				updatePS1Score(1);
				if (m_score1 == 5)
				{
					m_tmap->findGameObjectByName("Ball")->getComponent<BallController2>()->setMoveSpeed(0.0f);
				}
			}
			else if ("Left" == m_tmap->getLayer("StaticColliders")->getGameObjects()[i]->getName())
			{
				updatePS2Score(1);
				if (m_score2 == 5)
				{
					m_tmap->findGameObjectByName("Ball")->getComponent<BallController2>()->setMoveSpeed(0.0f);
				}
			}
		}
	}
	for (int i = 0; i < m_tmap->getLayer("DynamicObjects")->getGameObjects().size(); i++)
	{
		if (m_tmap->findGameObjectByName("Ball")->collidesTo(m_tmap->getLayer("DynamicObjects")->getGameObjects()[i], &check))
		{
			m_tmap->findGameObjectByName("Ball")->getComponent<BallController2>()->collisionCheck(m_tmap->getLayer("DynamicObjects")->getGameObjects()[i], deltaTime);
		}
	}

	m_tmap->update(deltaTime);
	return true;
}

void GameRunningState2::updatePS1Score(int m_score)
{
	m_score1 += m_score;
	m_scoreFont1->getComponent<TextComponent>()->getText()->setText(std::to_string(m_score1));

	if (m_score1 == 5)
	{
		m_p1Win->getComponent<TextComponent>()->getText()->setText("Player 1 wins! Press Esc for Main Menu.. ");
		m_p1Win->getComponent<TextComponent>()->getText()->setColor(200, 200, 200, 1);
		m_p1Win->setSize(vec2(64.0f, 64.0f) * 1.5f);
		m_p1Win->setPosition(9.0f, 2.0f);
	}

}

void GameRunningState2::updatePS2Score(int m_score)
{
	m_score2 += m_score;
	m_scoreFont2->getComponent<TextComponent>()->getText()->setText(std::to_string(m_score2));

	if (m_score2 == 5)
	{
		m_p2Win->getComponent<TextComponent>()->getText()->setText("Player 2 wins! Press Esc for Main Menu..");
		m_p2Win->getComponent<TextComponent>()->getText()->setColor(200, 200, 200, 1);
		m_p2Win->setSize(vec2(64.0f, 64.0f) * 1.5f);
		m_p2Win->setPosition(9.0f, 2.0f);
	}
}


void GameRunningState2::render(ESContext* ctx)
{
	// Set OpenGL clear color
	glClearColor(0.3f, 0.3f, 0.3f, 1.0f);

	// Clear the color buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	
	
	// Screen size to camera
	m_tmap->getCamera()->setScreenSize(ctx->width, ctx->height);

	// HAX: Tiled and yam2d y-coordinates works differently.
	// First you must make vec2 temp's, so that u can get their positions and add + 1.0f to y-coordinate
	// Then you render the map, and after that, you set player paddles to the new positions.
	vec2 temp1 = m_tmap->findGameObjectByName("PlayerPad1")->getPosition();
	m_tmap->findGameObjectByName("PlayerPad1")->setPosition(temp1 + vec2(0.0f, 1.0f));
	vec2 temp2 = m_tmap->findGameObjectByName("PlayerPad2")->getPosition();
	m_tmap->findGameObjectByName("PlayerPad2")->setPosition(temp2 + vec2(0.0f, 1.0f));
	
	// Render map and all of its layers containing GameObjects to screen.
	m_tmap->render();

	m_tmap->findGameObjectByName("PlayerPad1")->setPosition(temp1);
	m_tmap->findGameObjectByName("PlayerPad2")->setPosition(temp2);
}

GameRunningState2::~GameRunningState2()
{
	// Delete your game content
	esLogMessage("Deinit");
}