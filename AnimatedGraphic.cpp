#include "AnimatedGraphic.h"

AnimatedGraphic::AnimatedGraphic(const LoaderParams* pParams) : SDLGameObject()
{

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