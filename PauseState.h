#ifndef PAUSE_STATE_H
#define PAUSE_STATE_H
#include <iostream>
#include <vector>
#include "GameState.h"
#include "GameObject.h"
#include "LoaderParams.h"
#include "Game.h"
#include "TextureManager.h"
#include "MenuButton.h"

class PauseState : public GameState
{
public:
	virtual void update(); 	
	virtual void render(); 

	virtual bool onEnter(); 
	virtual bool onExit(); 

	virtual std::string getStateID() const { return s_playID;}
private:

	static void s_pauseToMain(); 
	static void s_resumePlay();

	static const std::string s_playID; 

	std::vector<GameObject*> m_gameObjects;
};
#endif//PAUSE_STATE_H