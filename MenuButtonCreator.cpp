#include "MenuButtonCreator.h"

GameObject* MenuButtonCreator::createGameObject() const
{
	return new MenuButton();
}