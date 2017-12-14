#include "AnimatedGraphicCreator.h"

GameObject* AnimatedGraphicCreator::createGameObject() const
{
	return new AnimatedGraphic();
}