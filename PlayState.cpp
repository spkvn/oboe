#include "PlayState.h"

const std::string PlayState::s_playID = "PLAY";  

void PlayState::update()
{
	if(TheInputHandler::instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		TheGame::instance()->getStateMachine()->pushState(new PauseState());
	}

	for(int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}

void PlayState::render()
{
	for(int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}

bool PlayState::onEnter()
{
	if(!TheTextureManager::instance()->load("assets/helicopter.png", "helicopter", TheGame::instance()->getRenderer()))
	{
		return false;
	}
	GameObject* player = new Player(new LoaderParams(100,100,89,57, "helicopter"));

	m_gameObjects.push_back(player);

	std::cout << "entering PlayState" << std::endl;

	return true;
}

bool PlayState::onExit()
{
	for(int i = 0; i < m_gameObjects.size(); i++ )
	{
		m_gameObjects[i]->clean();
	}

	m_gameObjects.clear(); 
	TheTextureManager::instance()->clearFromTextureMap("helicopter");

	std::cout << "exiting PlayState" << std::endl;
	return true;
}