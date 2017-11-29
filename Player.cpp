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
	m_velocity.setX(0);
	m_velocity.setY(0);

	handleInput();

	m_currentFrame = m_width * int(((SDL_GetTicks()/100)%6));

	SDLGameObject::update();
}

void Player::clean()
{
}

void Player::handleInput()
{
	if( TheInputHandler::instance()->xvalue(0,1) > 0 || 
		TheInputHandler::instance()->xvalue(0,1) < 0 )
	{
		m_velocity.setX(1 * TheInputHandler::instance()->xvalue(0,1));
	}

	if( TheInputHandler::instance()->yvalue(0,1) < 0 || 
		TheInputHandler::instance()->yvalue(0,1) > 0 )
	{
		m_velocity.setY(1 * TheInputHandler::instance()->yvalue(0,1));
	}

	if( TheInputHandler::instance()->xvalue(0,2) > 0 || 
		TheInputHandler::instance()->xvalue(0,2) < 0 )
	{
		m_velocity.setX(1 * TheInputHandler::instance()->xvalue(0,2));
	}

	if( TheInputHandler::instance()->yvalue(0,2) < 0 || 
		TheInputHandler::instance()->yvalue(0,2) > 0 )
	{
		m_velocity.setY(1 * TheInputHandler::instance()->yvalue(0,2));
	}

	if( TheInputHandler::instance()->getMouseButtonState(LEFT))
	{
		m_velocity.setX(1);
	}
	else
	{
		std::cout << "L Mouse Up" << std::endl;
		m_velocity.setX(-1);
	}
}