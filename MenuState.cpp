#include "MenuState.h"

const std::string MenuState::s_menuID = "MENU"; 

void MenuState::update()
{
	
}

void MenuState::render()
{

}

bool MenuState::onEnter()
{
	std::cout << "enter MenuState" << std::endl; 
	return true;
}


bool MenuState::onExit()
{
	std::cout << "exiting MenuState" << std::endl;
	return true;
}