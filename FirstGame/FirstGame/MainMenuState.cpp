#include "MainMenuState.h"


MainMenuState::MainMenuState(GameApp* app) : GameState(app), m_app(app), m_map(0), backgroundLayer(0), objectsLayer(0)
{
	// Tile size
	vec2 tileSize(200, 52);

	// Create new map, with width == tile, heigh == 32pixels/tile
	m_map = new Map(tileSize.x, tileSize.y);

	// Background layer
	backgroundLayer = new Layer(m_map, "Background", 1.0f, true, false);

	m_map->addLayer(Map::BACKGROUND0, backgroundLayer);

	// Create new sprite GameObject from texture (background sprite) size is same than screen size.
	GameObject* backgroundGameObject = createSpriteGameObject("meepobackground.png", 1280.0f, 720.0f, false);

	// Add GameObject to background layer.
	backgroundLayer->addGameObject(backgroundGameObject);

	// Objects layer
	objectsLayer = new Layer(m_map, "Objects", 1.0f, true, false);

	m_map->addLayer(Map::MAPLAYER0, objectsLayer);

	// Create new start button object, and clip it from texture postion <0,0> - <200, 52>, white color shall be transparent
	GameObject* startButtonObject = createSpriteGameObject("buttons2.png", tileSize.x, tileSize.y, 0, 0, 200, 52, true);
	
	// Add start button to level
	objectsLayer->addGameObject(startButtonObject);

	// Set start button position
	startButtonObject->setPosition(vec2(-0.6, 2));

	// Setting object names
	startButtonObject->setName("Start");

	// Create new start button object, and clip it from texture postion <200,0> - <200, 52>, white color shall be transparent
	GameObject* exitButtonObject = createSpriteGameObject("buttons2.png", tileSize.x, tileSize.y, 200, 0, 200, 52, true);

	// Add exit button to level
	objectsLayer->addGameObject(exitButtonObject);

	// Set exit button position
	exitButtonObject->setPosition(vec2(0.6, 2));

	// Setting object names
	exitButtonObject->setName("Exit");
}

GameObject* MainMenuState::createSpriteGameObject(const std::string& bitmapFileName, float sizeX, float sizeY, bool isWhiteTransparentColor = false)
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

	// Add sprite component to game object
	gameObject->addComponent(sprite);
	return gameObject;
}

GameObject* MainMenuState::createSpriteGameObject(const std::string& bitmapFileName, float sizeX, float sizeY, int clipStartX, int clipStartY, int clipSizeX, int clipSizeY, bool isWhiteTransparentColor = false)
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

bool MainMenuState::update(ESContext* ctx, float deltaTime)
{
	// Read mouse values
	float mouseX = float(getMouseAxisX());
	float mouseY = float(getMouseAxisY());

	// Convert mouse coordinates to map coordinates.
	vec2 mouseInMapCoordinates = m_map->screenToMapCoordinates(mouseX, mouseY);
	
	pickedObject = m_map->getLayer("Objects")->pick(mouseInMapCoordinates);

	std::string start = "Start";
	std::string exit = "Exit";

	if (pickedObject != nullptr)
	{
		std::string test1 = pickedObject->getName();
		if (test1.compare(start) == 0 && getMouseButtonState(MOUSE_LEFT) == 1)
		{
			esLogMessage("Object %s picked!", pickedObject->getName().c_str());
			getApp()->setState(new GameRunningState(getApp()));
			return true;
		}
		else if (test1.compare(exit) == 0 && getMouseButtonState(MOUSE_LEFT) == 1)
		{
			esLogMessage("Object %s picked!", pickedObject->getName().c_str());
			return false;
		}
	}
	else
	{
		// Update map. this will update all GameObjects inside a map layers.
		m_map->update(deltaTime);
	}
}

void MainMenuState::render(ESContext* ctx)
{
	// Set OpenGL clear color (dark gray)
	glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

	// Clear the color buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

	// Set screen size to camera.
	m_map->getCamera()->setScreenSize(ctx->width, ctx->height, 720, 1280.0f / 720.0f);

	// Render map and all of its layers containing GameObjects to screen.
	m_map->render();
}

MainMenuState::~MainMenuState()
{
	// Delete map
	//delete m_map;
}