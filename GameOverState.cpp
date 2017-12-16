#include "GameOverState.h"

const std::string GameOverState::s_gameOverID = "GAMEOVER"; 

void GameOverState::update()
{
	for(int i =0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}

void GameOverState::render()
{
	for(int i =0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}

bool GameOverState::onEnter()
{
	StateParser stateParser; 
	stateParser.parseState("conf/gameover.xml", s_gameOverID, &m_gameObjects, &m_textureIDList); 

	m_callbacks.push_back(0);
	m_callbacks.push_back(s_gameOverToMain);
	m_callbacks.push_back(s_restartPlay);

	setCallbacks(m_callbacks);

	std::cout << "Entering GameOver State" << std::endl;

	return true;
}


void GameOverState::setCallbacks(const std::vector<Callback>& callbacks)
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

bool GameOverState::onExit()
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

	std::cout << "Exiting GameOverState" << std::endl;
	return true;
}

void GameOverState::s_gameOverToMain()
{
	TheGame::instance()->getStateMachine()->changeState(new MainMenuState());
}

void GameOverState::s_restartPlay()
{
	std::cout << "before leaving gameover state" << std::endl;
	TheGame::instance()->getStateMachine()->changeState(new PlayState());
	std::cout << "after leaving gameover state" << std::endl;
}