#include "Player.h"
Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams)
{
}
void Player::draw()
{
	SDLGameObject::draw();
}

void Player::update()
{
	m_currentFrame = m_width * int(((SDL_GetTicks()/100)%6));

	m_acceleration.setX(0.00001);
	m_acceleration.setY(0.00001);

	SDLGameObject::update();
}

void Player::clean()
{
}