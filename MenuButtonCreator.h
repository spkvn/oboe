#ifndef MENU_BUTTON_CREATOR_H
#define MENU_BUTTON_CREATOR_H
#include "BaseCreator.h"
#include "MenuButton.h"

class MenuButtonCreator : public BaseCreator
{
	GameObject* createGameObject() const;
};


#endif//MENU_BUTTON_CREATOR_H