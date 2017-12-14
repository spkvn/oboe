#include "EnemyCreator.h"

GameObject* EnemyCreator::createGameObject() const
{
	return new Enemy();
}