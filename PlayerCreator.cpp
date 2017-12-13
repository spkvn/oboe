#include "PlayerCreator.h"

GameObject* PlayerCreator::createGameObject() const
{
	return new Player();
}