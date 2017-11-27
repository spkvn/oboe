#include "Game.h"
#include "Enemy.h"
#include "Player.h"
#include "InputHandler.h"

Game* Game::s_pInstance = 0;

bool Game::init(const char* title, int xpos, int ypos, int height, int width, int flags)
{
	if(SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		m_bRunning =  initGlobals(title, xpos,ypos,height,width,flags);

		TheInputHandler::instance()->initialiseJoysticks();

		if(m_bRunning)
		{
			m_gameObjects.push_back(new Player(new LoaderParams(100,100,76,53,"animate")));
			m_gameObjects.push_back(new Enemy(new LoaderParams(200,200,76,53,"animate")));

			m_bRunning =  TheTextureManager::instance()->load("assets/doggy.png","animate", m_pRenderer);
		}
	}
	else
	{
		m_bRunning = false;
	}

	return m_bRunning;
}

void Game::render()
{
	//clear the window
	SDL_RenderClear(m_pRenderer);

	//game objects
	for(std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}

	//show the window
	SDL_RenderPresent(m_pRenderer);
}

void Game::update()
{
	for(std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}

void Game::handleEvents()
{
	TheInputHandler::instance()->update();
	//do nothing yet
	// SDL_Event event;
	// if(SDL_PollEvent(&event))
	// {
	// 	switch(event.type)
	// 	{
	// 		case SDL_QUIT:
	// 			m_bRunning = false;
	// 			break;

	// 		default:
	// 			break;
	// 	}
	// }
}

void Game::clean()
{
	TheInputHandler::instance()->clean();
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}

bool Game::running()
{
	return m_bRunning;
}

bool Game::initGlobals(const char* title, int xpos, int ypos, int height, int width, int flags)
{
	m_pWindow = SDL_CreateWindow(
		title,
		xpos,
		ypos,
		height,
		width,
		flags
	);

	if(m_pWindow != 0)
	{
		m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
		//set to white
		SDL_SetRenderDrawColor(m_pRenderer,0,0,0,255);
	}
	else
	{
		return false;
	}
	return true;
}

void Game::quit()
{
	m_bRunning = false;
}
