#include "GameObjectFactory.h"

//allocating & initializing InputHandler pointer.
GameObjectFactory* GameObjectFactory::s_pInstance = 0;

bool GameObjectFactory::registerType(std::string typeId, BaseCreator* pCreator)
{
	std::map<std::string, BaseCreator*>::iterator it = m_creators.find(typeId);

	//if type already registered, do nothing.
	if(it != m_creators.end())
	{
		delete pCreator;
		std::cout << "GameObjectFactory::registerType(): " << typeId << " is already registered" << std::endl; 
		return false;
	}

	m_creators[typeId] = pCreator;

	return true;
}

GameObject* GameObjectFactory::create(std::string typeId)
{
	std::map<std::string, BaseCreator*>::iterator it = m_creators.find(typeId);

	if(it == m_creators.end())
	{
		std::cout << "Could not find type: " << typeId <<std::endl;
		return NULL;
	}

	// BaseCreator* pCreator = (*it).second;
	BaseCreator* pCreator = it->second;

	return pCreator->createGameObject();
}

GameObjectFactory* GameObjectFactory::instance()
{	
	if(s_pInstance == 0)
	{
		s_pInstance = new GameObjectFactory();
		return s_pInstance;
	}

	return s_pInstance;
}