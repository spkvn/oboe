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
	if(!TheTextureManager::instance()->load("assets/gameOver.png","gameovertext",TheGame::instance()->getRenderer()))
	{
		//failed to load startButton
		return false;
	}

	if(!TheTextureManager::instance()->load("assets/mainMenuButton.png","mainbutton",TheGame::instance()->getRenderer()))
	{
		//failed to load exitButton
		return false;
	}
	
	if(!TheTextureManager::instance()->load("assets/restartButton.png","restartbutton",TheGame::instance()->getRenderer()))
	{
		//failed to load exitButton
		return false;
	}

	GameObject* gameOverText = new AnimatedGraphic( new LoaderParams(200,100,256,64,"gameovertext"),2);
	GameObject* button1 = new MenuButton( new LoaderParams(200,200,64,32,"restartbutton") , s_restartPlay);
	GameObject* button2 = new MenuButton( new LoaderParams(200,300,64,32,"mainbutton") , s_gameOverToMain);

	m_gameObjects.push_back(gameOverText);
	m_gameObjects.push_back(button1);
	m_gameObjects.push_back(button2);

	std::cout << "Entering GameOverState" << std::endl;
	return true;
}


bool GameOverState::onExit()
{
	for(int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();

	TheTextureManager::instance()->clearFromTextureMap("gameovertext");
	TheTextureManager::instance()->clearFromTextureMap("restartbutton");
	TheTextureManager::instance()->clearFromTextureMap("exitbutton");

	std::cout << "Exiting GameOverState" << std::endl;
	return true;
}

void GameOverState::s_gameOverToMain()
{
	TheGame::instance()->getStateMachine()->changeState(new MenuState());
}

void GameOverState::s_restartPlay()
{
	TheGame::instance()->getStateMachine()->changeState(new PlayState());
}