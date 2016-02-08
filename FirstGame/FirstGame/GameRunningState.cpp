#include "GameRunningState.h"

GameRunningState::GameRunningState(GameApp* app) : GameState(app), m_tmap(0), m_componentFactory(0), m_paddle(0), objectsLayer(0)
{
	esLogMessage("Initializing Level 1!");
	m_tmap = new TmxMap();
	m_componentFactory = new DefaultComponentFactory();

	bool okay = m_tmap->loadMapFile("assets/level.tmx", m_componentFactory);

	if (okay)
	{
		m_tmap->getCamera()->setPosition(vec2(m_tmap->getWidth() / 2.0f - 0.5f, m_tmap->getHeight() / 2.0f - 0.5f));
	}

	objectsLayer = new Layer(m_tmap, "Objects", 1.0f, true, false);

	m_tmap->addLayer(Map::MAPLAYER1, objectsLayer);

	// 256x64
	m_paddle = createSpriteGameObject("assets/glasspaddle2.png", 256.0f, 64.0f, 0, 0, 256.0f, 64.0f, true);
	
	objectsLayer->addGameObject(m_paddle);

	m_paddle->setPosition(vec2(0, 4));

	m_paddle->setName("Paddle");
}

GameObject* GameRunningState::createSpriteGameObject(const std::string& bitmapFileName, float sizeX, float sizeY, int clipStartX, int clipStartY, int clipSizeX, int clipSizeY, bool isWhiteTransparentColor = false)
{
	// Load texture to be used as texture for sprite.
	Texture* texture = new Texture(bitmapFileName.c_str());

	// If user wants to create texture which white coros is treated as atransparent color.
	if (isWhiteTransparentColor)
	{
		// Set white to transparent. Here color values are from 0 to 255 (RGB)
		texture->setTransparentColor(255, 255, 255);
	}

	// Create new sprite GameObject from texture.
	GameObject* gameObject = new GameObject(0, 0);
	SpriteComponent* sprite = new SpriteComponent(gameObject, texture);

	// Resize the sprite to be correct size
	gameObject->setSize(sizeX, sizeY);

	// Specify clip area by start point and size in pixels
	Sprite::PixelClip clip;
	clip.topLeft.x = clipStartX;
	clip.topLeft.y = clipStartY;
	clip.clipSize.x = clipSizeX;
	clip.clipSize.y = clipSizeY;

	// Set pixel clip for sprite
	sprite->getSprite()->setClip(float(texture->getWidth()), float(texture->getHeight()), clip);

	// Add sprite component to game object
	gameObject->addComponent(sprite);
	return gameObject;
}

float GameRunningState::getZoom()
{
	return zoom;
}

void GameRunningState::setZoom(float newZoom)
{
	zoom = slm::clamp(newZoom, 0.25f, 8.0f);
}

void GameRunningState::moveGameObject(GameObject paddle, float speed, float deltaTime, bool moveDirection)
{
	// Get move direction from keyboard
	//vec2 direction;
}

bool GameRunningState::update(ESContext* ctx, float deltaTime)
{
	setZoom(getZoom() + getMouseWheelDelta());

	if (getKeyState(KEY_ESCAPE) == 1)
	{
		getApp()->setState(new MainMenuState(getApp()));
		return true;
		//return false;
	}
	m_tmap->update(deltaTime);
	return true;
}

void GameRunningState::render(ESContext* ctx)
{
	// Set OpenGL clear color
	glClearColor(0.5f, 0.0f, 0.0f, 1.0f);

	// Clear the color buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Set screen size to camera.
	m_tmap->getCamera()->setScreenSize(ctx->width, ctx->height, 400 / getZoom());

	// Render map and all of its layers containing GameObjects to screen.
	m_tmap->render();
}

GameRunningState::~GameRunningState()
{
	// Delete game stuff
	esLogMessage("Deinit");
	delete m_tmap;
	delete m_componentFactory;
	delete m_paddle;
}