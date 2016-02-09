#pragma once
#include "GameState.h"

class MyGameComponentFactory : public DefaultComponentFactory
{
public:
	MyGameComponentFactory();
	~MyGameComponentFactory();
	
	virtual Component* createNewComponent(const std::string& type, Entity* owner, const PropertySet& properties);
	virtual Entity* createNewEntity(ComponentFactory* m_componentFactory, const std::string& type, Entity* parent, const PropertySet& properties);
private:
	Ref<GameObject> m_gameObject;
};