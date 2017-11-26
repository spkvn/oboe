#ifndef GAME_H
#define GAME_H 
#include <vector>
#include <SDL2/SDL.h>
#include "GameObject.h"

class Game
{
public:
	~Game() {}

	bool init(const char* title, int xpos, int ypos, int height, int width, int flags);
	void render();
	void update();
	void handleEvents(); 
	void clean(); 

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
};

typedef Game TheGame;
#endif	// GAME_H