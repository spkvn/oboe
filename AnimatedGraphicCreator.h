#ifndef ANIMATED_GRAPHIC_CREATOR_H
#define ANIMATED_GRAPHIC_CREATOR_H
#include "BaseCreator.h"
#include "AnimatedGraphic.h"

class AnimatedGraphicCreator : public BaseCreator
{
	GameObject* createGameObject() const;
};


#endif//ANIMATED_GRAPHIC_CREATOR_H