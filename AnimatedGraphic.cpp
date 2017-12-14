#include "AnimatedGraphic.h"

AnimatedGraphic::AnimatedGraphic() : SDLGameObject()
{
}

void AnimatedGraphic::load(const LoaderParams* pParams)
{
	SDLGameObject::load(pParams);
	m_animSpeed = pParams->getAnimSpeed();
}

void AnimatedGraphic::draw()
{
	SDLGameObject::draw();
}

void AnimatedGraphic::update()
{
	m_currentFrame = int(((SDL_GetTicks() / (1000 / m_animSpeed)) % 2 ));

}

void AnimatedGraphic::clean()
{
	SDLGameObject::clean();
}