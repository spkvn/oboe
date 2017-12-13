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

	if( checkCollision(dynamic_cast<SDLGameObject*>(m_gameObjects[0]), dynamic_cast<SDLGameObject*>(m_gameObjects[1])))
	{
		TheGame::instance()->getStateMachine()->pushState(new GameOverState());
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
	// if(!TheTextureManager::instance()->load("assets/helicopter.png", "helicopter", TheGame::instance()->getRenderer()))
	// {
	// 	return false;
	// }
	
	// if(!TheTextureManager::instance()->load("assets/helicopter2.png", "helicopter2", TheGame::instance()->getRenderer()))
	// {
	// 	return false;
	// }

	// GameObject* player = new Player(new LoaderParams(500,100,89,57, "helicopter"));
	// GameObject* enemy = new Enemy(new LoaderParams(100,100,89,57, "helicopter2"));

	// m_gameObjects.push_back(player);
	// m_gameObjects.push_back(enemy);

	// std::cout << "entering PlayState" << std::endl;

	// return true;
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

bool PlayState::checkCollision(SDLGameObject* p1, SDLGameObject* p2)
{
	int leftA, leftB, rightA, rightB, topA, topB, bottomA, bottomB;

	leftA   = p1->getPosition().getX();
	rightA  = p1->getPosition().getX() + p1->getWidth();
	topA    = p1->getPosition().getY();
	bottomA = p1->getPosition().getY() + p1->getHeight();
	
	leftB   = p2->getPosition().getX();
	rightB  = p2->getPosition().getX() + p2->getWidth();
	topB    = p2->getPosition().getY();
	bottomB = p2->getPosition().getY() + p2->getHeight();

	if(
		bottomA <= topB || 
		topA >= bottomB || 
		rightA <= leftB || 
		leftA >= rightB
	)
	{
		return false;
	}

	return true;
}