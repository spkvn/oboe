#ifndef GAME_OVER_STATE_H
#define GAME_OVER_STATE_H

#include <iostream>
#include <vector>

#include "GameState.h"
#include "GameObject.h"
#include "LoaderParams.h"
#include "Game.h"
#include "TextureManager.h"
#include "MenuButton.h"
#include "AnimatedGraphic.h"


class GameOverState : public GameState
{
public:
	virtual void update(); 
	virtual void render(); 

	virtual bool onEnter(); 
	virtual bool onExit(); 

	virtual std::string getStateID() const { return s_gameOverID;}
private:
	static const std::string s_gameOverID;
	std::vector<GameObject*> m_gameObjects;

	//callback functions for menu items
	static void s_restartPlay();
	static void s_gameOverToMain();
};


#endif//GAME_OVER_STATE_H