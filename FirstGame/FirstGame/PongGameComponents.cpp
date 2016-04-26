#include "PongGameComponents.h"

PongGameComponents::PongGameComponents(TmxMap* map)
	: DefaultComponentFactory()
	, m_gameObject(0)
	, m_map(map)
	, m_fontTexture(new Texture("assets/Fixedsys_24_Bold.png"))
	, m_font(SpriteSheet::autoFindFontFromTexture(m_fontTexture, "assets/Fixedsys_24_Bold.dat"))
{
	m_map->addLayer(TmxMap::BACKGROUND0, new Layer(m_map, "Background", 0.5f, true, false));
}

Component* PongGameComponents::createNewComponent(const std::string& type, Entity* owner, const PropertySet& properties)
{
	return DefaultComponentFactory::createNewComponent(type, owner, properties);
}

Entity* PongGameComponents::createNewEntity(ComponentFactory* m_componentFactory, const std::string& type, Entity* parent, const PropertySet& properties)
{

	// Tiled names: "Ball", "PlayerPad1" and "PlayerPad2".

	if ("StaticColliders" == type)
	{
		m_gameObject = new GameObject(parent, properties);
		return m_gameObject;
	}
	else if ("Ball" == type)
	{
		m_gameObject = new GameObject(parent, properties);
		m_gameObject->addComponent(m_componentFactory->createNewComponent("Tile", m_gameObject, properties));
		BallController2* ballController2 = new BallController2(m_gameObject);
		m_gameObject->addComponent(ballController2);
		m_gameObject->setName("Ball");
		return m_gameObject;
	}
	else if ("PlayerPad1" == type)
	{
		m_gameObject = new GameObject(parent, properties);
		m_gameObject->addComponent(m_componentFactory->createNewComponent("Tile", m_gameObject, properties));
		Paddle1Controller* paddle1Controller = new Paddle1Controller(m_gameObject);
		m_gameObject->addComponent(paddle1Controller);
		m_gameObject->setName("PlayerPad1");
		return m_gameObject;
	}

	else if ("PlayerPad2" == type)
	{
		m_gameObject = new GameObject(parent, properties);
		m_gameObject->addComponent(m_componentFactory->createNewComponent("Tile", m_gameObject, properties));
		Paddle2Controller* paddle2Controller = new Paddle2Controller(m_gameObject);
		m_gameObject->addComponent(paddle2Controller);
		m_gameObject->setName("PlayerPad2");
		return m_gameObject;
	}

	else if ("Score" == type)
	{
		m_gameObject = new GameObject(nullptr, 0);
		m_gameObject->setType(type);
		m_gameObject->addComponent(new TextComponent(m_gameObject, m_font));
		m_map->getLayer("Background")->addGameObject(m_gameObject);
		return m_gameObject;
	}

	// Default functionality.
	Entity* res = DefaultComponentFactory::createNewEntity(m_componentFactory, type, parent, properties);
	assert(res != 0);
	return res;
}
PongGameComponents::~PongGameComponents()
{
}