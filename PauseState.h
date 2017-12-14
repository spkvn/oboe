#ifndef PAUSE_STATE_H
#define PAUSE_STATE_H
#include <iostream>
#include <vector>
#include "MenuState.h"
#include "MainMenuState.h"
#include "GameObject.h"
#include "LoaderParams.h"
#include "Game.h"
#include "TextureManager.h"
#include "MenuButton.h"
#include "StateParser.h"

class PauseState : public MenuState
{
public:
	virtual void update(); 	
	virtual void render(); 

	virtual bool onEnter(); 
	virtual bool onExit(); 

	virtual void setCallbacks(const std::vector<Callback>& callbacks);

	virtual std::string getStateID() const { return s_pauseID;}
private:

	static void s_pauseToMain(); 
	static void s_resumePlay();

	static const std::string s_pauseID; 

	std::vector<GameObject*> m_gameObjects;
};
#endif//PAUSE_STATE_H