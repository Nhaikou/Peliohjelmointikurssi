#pragma once
#include "GameState.h"
#include "TextComponent.h"
#include "Paddle1Controller.h"
#include "Paddle2Controller.h"
#include "BallController2.h"	// Pong ball

class PongGameComponents : public DefaultComponentFactory
{
public:
	PongGameComponents(TmxMap* map);
	virtual~PongGameComponents();

	virtual Component* createNewComponent(const std::string& type, Entity* owner, const PropertySet& properties);
	virtual Entity* createNewEntity(ComponentFactory* m_componentFactory, const std::string& type, Entity* parent, const PropertySet& properties);
private:
	Ref<GameObject> m_gameObject;
	Ref<TmxMap> m_map;
	Ref<Texture> m_fontTexture;
	Ref<SpriteSheet> m_font;
};

