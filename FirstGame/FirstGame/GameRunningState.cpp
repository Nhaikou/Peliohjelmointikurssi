#include "GameRunningState.h"

GameRunningState::GameRunningState(GameApp* app) : GameState(app), map(0)
{
	esLogMessage("Initializing Level 1!");
	map = new TmxMap();
	componentFactory = new DefaultComponentFactory();

	bool okay = map->loadMapFile("assets/level.tmx", componentFactory);

	if (okay)
	{
		map->getCamera()->setPosition(vec2(map->getWidth() / 2.0f - 0.5f, map->getHeight() / 2.0f - 0.5f));
	}
}
float GameRunningState::getZoom()
{
	return zoom;
}

void GameRunningState::setZoom(float newZoom)
{
	zoom = slm::clamp(newZoom, 0.25f, 8.0f);
}

bool GameRunningState::update(ESContext* ctx, float deltaTime)
{
	setZoom(getZoom() + getMouseWheelDelta());

	map->update(deltaTime);

	if (GetKeyState(KEY_ESCAPE))
	{
		return false;
	}

	return true;
}

void GameRunningState::render(ESContext* ctx)
{
	// Set OpenGL clear color
	glClearColor(0.5f, 0.0f, 0.0f, 1.0f);

	// Clear the color buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Set screen size to camera.
	map->getCamera()->setScreenSize(ctx->width, ctx->height, 400/getZoom());

	// Render map and all of its layers containing GameObjects to screen.
	map->render();
}

GameRunningState::~GameRunningState()
{
	// Delete game stuff
	esLogMessage("Deinit");
	delete map;
	delete componentFactory;
}