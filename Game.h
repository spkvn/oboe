#ifndef GAME_H
#define GAME_H 
#include <vector>
#include <SDL2/SDL.h>
#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"
#include "PlayerCreator.h"
#include "EnemyCreator.h"
#include "InputHandler.h"
#include "GameStateMachine.h"
#include "PlayState.h"
#include "MainMenuState.h"
#include "GameObjectFactory.h"
#include "BaseCreator.h"
#include "MenuButtonCreator.h"

class Game
{
public:
	~Game() {}

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
private:
	Game() {}
	static Game* s_pInstance; 


	SDL_Texture* m_pTexture;
	SDL_Rect m_sourceRectangle;
	SDL_Rect m_destinationRectangle;

	int m_currentFrame; 
	
	//game object vector
	std::vector<GameObject*> m_gameObjects;

	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	bool m_bRunning; 

	bool initGlobals(const char* title, int xpos, int ypos, int height, int width, int flags);

	GameStateMachine* m_pGameStateMachine;
};

typedef Game TheGame;

#endif	// GAME_H