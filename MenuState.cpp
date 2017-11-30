#include "MenuState.h"

const std::string MenuState::s_menuID = "MENU"; 

void MenuState::update()
{
	for(int i =0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}

void MenuState::render()
{
	for(int i =0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}

bool MenuState::onEnter()
{
	if(!TheTextureManager::instance()->load("assets/startButton.png","startButton",TheGame::instance()->getRenderer()))
	{
		//failed to load startButton
		return false;
	}

	if(!TheTextureManager::instance()->load("assets/exitButton.png","exitButton",TheGame::instance()->getRenderer()))
	{
		//failed to load exitButton
		return false;
	}

	GameObject* button1 = new MenuButton( new LoaderParams(100,100,64,32,"startButton") , s_menuToPlay);
	GameObject* button2 = new MenuButton( new LoaderParams(100,300,64,32,"exitButton") , s_exitFromMenu);

	m_gameObjects.push_back(button1);
	m_gameObjects.push_back(button2);

	std::cout << "Entering MenuState" << std::endl;
	return true;
}


bool MenuState::onExit()
{
	for(int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();
	TheTextureManager::instance()->clearFromTextureMap("startButton");
	TheTextureManager::instance()->clearFromTextureMap("exitButton");

	std::cout << "Exiting MenuState" << std::endl;
	return true;
}

void MenuState::s_menuToPlay()
{
	TheGame::instance()->getStateMachine()->changeState(new PlayState());
}

void MenuState::s_exitFromMenu()
{
	TheGame::instance()->quit();
}