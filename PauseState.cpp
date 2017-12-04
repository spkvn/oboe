#include "PauseState.h"

const std::string PauseState::s_playID = "PAUSE";  

void PauseState::s_pauseToMain()
{
	TheGame::instance()->getStateMachine()->changeState(new MenuState());
}

void PauseState::s_resumePlay()
{
	TheGame::instance()->getStateMachine()->popState();
}

void PauseState::update()
{
	for(int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}

void PauseState::render()
{
	for(int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}

bool PauseState::onEnter()
{
	if(!TheTextureManager::instance()->load("assets/resumeButton.png", "resumebutton", TheGame::instance()->getRenderer()))
	{
		return false;
	}

	if(!TheTextureManager::instance()->load("assets/mainMenuButton.png", "mainbutton", TheGame::instance()->getRenderer()))
	{
		return false;
	}

	GameObject* button1 = new MenuButton(
		new LoaderParams(
			100,100,64,32,"mainbutton"
		),
		s_pauseToMain
	);

	GameObject* button2 = new MenuButton(
		new LoaderParams(
			100,300,64,32,"resumebutton"
		),
		s_resumePlay
	);

	m_gameObjects.push_back(button1);
	m_gameObjects.push_back(button2);

	std::cout << "entering PauseState" << std::endl;
	return true;
}

bool PauseState::onExit()
{
	for(int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}

	m_gameObjects.clear(); 

	TheTextureManager::instance()->clearFromTextureMap("resumebutton");
	TheTextureManager::instance()->clearFromTextureMap("mainbutton");

	TheInputHandler::instance()->reset();

	std::cout << "exiting PauseState" << std::endl;

	return true;
}