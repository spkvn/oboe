#ifndef GAME_OBJECT_FACTORY_H
#define GAME_OBJECT_FACTORY_H

#include <iostream>

#include "BaseCreator.h"

class GameObjectFactory
{
public:
	bool registerType(std::string typeId, BaseCreator* pCreator);
	GameObject* create(std::string typeId);
	static GameObjectFactory* instance();
private:
	std::map<std::string, BaseCreator*> m_creators;
	static GameObjectFactory* s_pInstance;
};

//defining singleton
typedef GameObjectFactory TheGameObjectFactory;

#endif//GAME_OBJECT_FACTORY_H