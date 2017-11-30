#ifndef MENU_STATE_H
#define MENU_STATE_H
#include <iostream>
#include <vector>
#include "GameState.h"
#include "GameObject.h"
#include "LoaderParams.h"
#include "Game.h"
#include "TextureManager.h"
#include "MenuButton.h"

class MenuState : public GameState
{
public:
	virtual void update(); 
	virtual void render(); 

	virtual bool onEnter(); 
	virtual bool onExit(); 

	virtual std::string getStateID() const { return s_menuID;}
private:
	static const std::string s_menuID;
	std::vector<GameObject*> m_gameObjects;
};

#endif//MENU_STATE_H