#include "MenuButton.h"

MenuButton::MenuButton(const LoaderParams* pParams) : SDLGameObject(pParams)
{
	m_currentFrame = MOUSE_OUT; //start at frame 2, because I've got my sprites backwards;
}

MenuButton::draw()
{
	SDLGameObject::draw(); // use base class drawing
}

MenuButton::update()
{
	Vector2D* pMousePos = TheInputHandler::instance()->getMousePosition(); 

	if(pMousePos->getX() < (m_position.getX() + m_width)
	&& pMousePos->getX() > m_position.getX()
	&& pMousePos->getY() < (m_position.getY() + m_height)
	&& pMousePos->getY() > m_position.getY())
	{
		m_currentFrame = MOUSE_OVER; 

		if(TheInputHandler::instance->getMouseButtonState(LEFT))
		{
			m_currentFrame = CLICKED;
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