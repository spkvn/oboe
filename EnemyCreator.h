#ifndef ENEMY_CREATOR_H
#define ENEMY_CREATOR_H
#include "BaseCreator.h"
#include "Enemy.h"

class EnemyCreator : public BaseCreator
{
	GameObject* createGameObject() const;
};


#endif//ENEMY_CREATOR_H