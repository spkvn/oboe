#ifndef BASE_CREATOR_H
#define BASE_CREATOR_H

#include <string>
#include <map>

#include "GameObject.h"

class BaseCreator
{
public:
	virtual GameObject* createGameObject() const = 0; 
	virtual ~BaseCreator(){}
};

#endif//BASE_CREATOR_H