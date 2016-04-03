#include "PongGameComponents.h"

PongGameComponents::PongGameComponents()
	: DefaultComponentFactory(), m_gameObject(0), m_map(0)
{

}

Component* PongGameComponents::createNewComponent(const std::string& type, Entity* owner, const PropertySet& properties)
{
	return DefaultComponentFactory::createNewComponent(type, owner, properties);
}

Entity* PongGameComponents::createNewEntity(ComponentFactory* m_componentFactory, const std::string& type, Entity* parent, const PropertySet& properties)
{

	// Tiled names: "Ball", "PlayerPad1", "PlayerPad2"

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

	// Default functionality.
	Entity* res = DefaultComponentFactory::createNewEntity(m_componentFactory, type, parent, properties);
	assert(res != 0);
	return res;
}
PongGameComponents::~PongGameComponents()
{
}