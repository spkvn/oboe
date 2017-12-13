#include "MenuButton.h"

MenuButton::MenuButton() : SDLGameObject(), m_callback(0), m_bReleased(true)
{
}

void MenuButton::draw()
{
	SDLGameObject::draw(); // use base class drawing
}

void MenuButton::load(const LoaderParams* pParams)
{
	SDLGameObject::load(pParams);
	m_callbackID = pParams->getCallbackID();
	m_currentFrame = MOUSE_OUT;
}



void MenuButton::update()
{
	Vector2D* pMousePos = TheInputHandler::instance()->getMousePosition(); 

	if(pMousePos->getX() < (m_position.getX() + m_width)
	&& pMousePos->getX() > m_position.getX()
	&& pMousePos->getY() < (m_position.getY() + m_height)
	&& pMousePos->getY() > m_position.getY())
	{
		if(TheInputHandler::instance()->getMouseButtonState(LEFT) && m_bReleased)
		{
			m_currentFrame = CLICKED;

			m_callback();	//call our callback function, passed in via ctor. 

			m_bReleased = false;
		}
		else if(!TheInputHandler::instance()->getMouseButtonState(LEFT))
		{
			m_bReleased = true;
			m_currentFrame = MOUSE_OVER;
		}
	}
	else
	{
		m_currentFrame = MOUSE_OUT;
	}
}

void MenuButton::clean()
{
	SDLGameObject::clean();
}