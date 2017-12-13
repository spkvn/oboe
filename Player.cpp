#include "Player.h"
Player::Player() : SDLGameObject()
{

}

void Player::load(const LoaderParams* pParams)
{
	SDLGameObject::load(pParams);
}

void Player::draw()
{
	SDLGameObject::draw();
}

void Player::update()
{
	m_velocity.setX(0);
	m_velocity.setY(0);

	handleInput();

	m_currentFrame = int(((SDL_GetTicks()/100)%4));
	SDLGameObject::update();
}

void Player::clean()
{
}

void Player::handleInput()
{
	Vector2D* target = TheInputHandler::instance()->getMousePosition();

	m_velocity = *target - m_position;

	m_velocity /= 50;
}