#include "Game.h"

Game* Game::s_pInstance = 0;

bool Game::init(const char* title, int xpos, int ypos, int height, int width, int flags)
{
	if(SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		m_bRunning =  initGlobals(title, xpos,ypos,height,width,flags);

		TheInputHandler::instance()->initialiseJoysticks();

		if(m_bRunning)
		{
//			TheGameObjectFactory::instance()->registerType("MenuButton", new MenuButtonCreator());
//			TheGameObjectFactory::instance()->registerType("AnimatedGraphic", new AnimatedGraphicCreator());
//			TheGameObjectFactory::instance()->registerType("Player", new PlayerCreator());
			TheGameObjectFactory::instance()->registerType("Tile", new TileCreator());
			m_pGameStateMachine = new GameStateMachine(); 
			m_pGameStateMachine->changeState(new PlayState());
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

    //render the state + it's objects
	m_pGameStateMachine->render();

	//show the window
	SDL_RenderPresent(m_pRenderer);
}

void Game::update()
{
	m_pGameStateMachine->update();
}

void Game::handleEvents()
{
	TheInputHandler::instance()->update();

	if(TheInputHandler::instance()->isKeyDown(SDL_SCANCODE_RETURN))
	{
		m_pGameStateMachine->changeState(new PlayState());
	}
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
		width,
		height,
		flags
	);

	m_gameWidth = width; 
	m_gameHeight = height;

	if(m_pWindow != 0)
	{
		m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
		//set to white
		SDL_SetRenderDrawColor(m_pRenderer,184,184,214,255);
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

Game::~Game()
{
    delete m_pTexture;
	delete m_pWindow;
	delete m_pRenderer;
    delete m_pGameStateMachine;
}

Game::Game()
{
}
