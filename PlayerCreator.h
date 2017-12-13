#ifndef PLAYER_CREATOR_H
#define PLAYER_CREATOR_H
#include "BaseCreator.h"
#include "Player.h"

class PlayerCreator : public BaseCreator
{
	GameObject* createGameObject() const;
};


#endif//PLAYER_CREATOR_H