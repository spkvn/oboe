#ifndef GAME_OBJECT_FACTORY_H
#define GAME_OBJECT_FACTORY_H

#include <iostream>

#include "BaseCreator.h"

class GameObjectFactory
{
public:
	bool registerType(std::string typeId, BaseCreator* pCreator);
	GameObject* create(std::string typeId);
private:
	std::map<std::string, BaseCreator*> m_creators;
};

#endif//GAME_OBJECT_FACTORY_H