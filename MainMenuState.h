#ifndef MAIN_MENU_STATE_H
#define MAIN_MENU_STATE_H
#include <iostream>
#include <vector>
#include <string>
#include "GameState.h"
#include "GameObject.h"
#include "LoaderParams.h"
#include "Game.h"
#include "TextureManager.h"
#include "MenuButton.h"
#include "MenuState.h"
#include "StateParser.h"

class MainMenuState : public MenuState
{
public:
	virtual void update(); 
	virtual void render(); 

	virtual bool onEnter(); 
	virtual bool onExit(); 

	virtual std::string getStateID() const { return s_menuID; }
private:
	virtual void setCallbacks(const std::vector<Callback>& callbacks);

	static const std::string s_menuID;
	std::vector<GameObject*> m_gameObjects;
	std::vector<std::string> m_textureIDList;

	//callback functions for menu items
	static void s_menuToPlay();
	static void s_exitFromMenu();
};

#endif//MAIN_MENU_STATE_H