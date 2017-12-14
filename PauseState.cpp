#include "PauseState.h"

const std::string PauseState::s_pauseID = "PAUSE";  

void PauseState::s_pauseToMain()
{
	TheGame::instance()->getStateMachine()->changeState(new MainMenuState());
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
	StateParser stateParser; 
	stateParser.parseState("conf/pause.xml", s_pauseID, &m_gameObjects, &m_textureIDList);

	m_callbacks.push_back(0);
	m_callbacks.push_back(s_resumePlay);
	m_callbacks.push_back(s_pauseToMain);

	setCallbacks(m_callbacks);

	std::cout << "Entering PauseState" << std::endl;

	return true;
}

void PauseState::setCallbacks(const std::vector<Callback>& callbacks)
{
	for(int i = 0; i < m_gameObjects.size(); i++)
	{
		if(dynamic_cast<MenuButton*>(m_gameObjects[i]))
		{
			MenuButton* pButton = dynamic_cast<MenuButton*>(m_gameObjects[i]);
			pButton->setCallback(callbacks[pButton->getCallbackID()]);
		}
	}
}

bool PauseState::onExit()
{
	for(int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}

	m_gameObjects.clear(); 

	for(int i = 0; i < m_textureIDList.size(); i++)
	{
		TheTextureManager::instance()->clearFromTextureMap(m_textureIDList[i]);
	}

	TheInputHandler::instance()->reset();

	std::cout << "exiting PauseState" << std::endl;

	return true;
}