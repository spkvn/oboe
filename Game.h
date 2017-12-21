#ifndef GAME_H
#define GAME_H 

#include <vector>
#include <SDL2/SDL.h>

#include "GameObjectFactory.h"
#include "TileCreator.h"
#include "InputHandler.h"
#include "GameStateMachine.h"
#include "PlayState.h"

class Game
{
public:
	~Game();

	bool init(const char* title, int xpos, int ypos, int height, int width, int flags);
	void render();
	void update();
	void handleEvents(); 
	void clean(); 
	void quit();

	//private mutators
	bool running();

	static Game* instance() 
	{
		if(s_pInstance == 0)
		{
			s_pInstance = new Game();
		}
		return s_pInstance;
	}

	SDL_Renderer* getRenderer() const { return m_pRenderer; }
	GameStateMachine* getStateMachine() const { return m_pGameStateMachine;}

	int getGameWidth(){return m_gameWidth;}
	int getGameHeight(){return m_gameHeight;}
private:
	Game();
	static Game* s_pInstance; 

	SDL_Texture* m_pTexture;
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
    GameStateMachine* m_pGameStateMachine;

    bool m_bRunning;
    int m_gameWidth;

	int m_gameHeight;

	bool initGlobals(const char* title, int xpos, int ypos, int height, int width, int flags);
};

typedef Game TheGame;

#endif	// GAME_H