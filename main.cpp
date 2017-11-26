#include "Game.h"

const int FPS = 60; 
const int DELAY_TIME = 1000.0f / FPS;

int main(int argc, char* argv)
{
	uint32 frameStart, frameTime;
	if(TheGame::instance()->init("Chapter 4",100,100,640,480,false))
	{
		while(TheGame::instance()->running())
		{
			frameStart = SDL_GetTicks(); 

			TheGame::instance()->handleEvents(); 
			TheGame::instance()->update();
			TheGame::instance()->render();

			frameTime = SDL_GetTicks() - frameStart;

			if(frameTime < DELAY_TIME)
			{
				SDL_Delay((int) (DELAY_TIME - frameTime));
			}
		}
	}
	else
	{
		return -1; 
	}
	return 0;
}