#include "Enemy.h"
Enemy::Enemy() : SDLGameObject()
{
}

void Enemy::load(const LoaderParams* pParams)
{
	SDLGameObject::load(pParams);
	m_velocity.setY(2);
}
void Enemy::draw()
{
	SDLGameObject::draw();
}

void Enemy::update()
{
	m_currentFrame = int(((SDL_GetTicks() / 100 ) % 4 ));

	if(m_position.getY() < 0)
	{
		m_velocity.setY(2);
	}
	else if(m_position.getY() > 400)
	{
		m_velocity.setY(-2);
	}

	SDLGameObject::update();
}

void Enemy::clean()
{
}