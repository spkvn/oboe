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

	// Have Player follow mouse.
	// Vector2D* vec = TheInputHandler::instance()->getMousePosition();
	// m_velocity = (*vec - m_position) / 100;
	
	// Starts moving right on click.
	// if( TheInputHandler::instance()->getMouseButtonState(LEFT))
	// {
	// 	m_velocity.setX(1);
	// }
	// else
	// {
	// 	m_velocity.setX(0);
	// }

	if(TheInputHandler::instance()->isKeyDown(SDL_SCANCODE_W))
	{
		m_velocity.setY(-2);
	}
	if(TheInputHandler::instance()->isKeyDown(SDL_SCANCODE_S))
	{
		m_velocity.setY(2);
	}
	if(TheInputHandler::instance()->isKeyDown(SDL_SCANCODE_D))
	{
		m_velocity.setX(2);
	}
	if(TheInputHandler::instance()->isKeyDown(SDL_SCANCODE_A))
	{
		m_velocity.setX(-2);
	}
}