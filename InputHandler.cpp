#include "InputHandler.h"

//allocating & initializing InputHandler pointer.
InputHandler* InputHandler::s_pInstance = 0;

InputHandler::InputHandler()
{
	//Handle Mouse buttons (left, mid, right)
	for(int i = 0; i < 3; i++)
	{
		m_mouseButtonStates.push_back(false);
	}

	m_mousePosition = new Vector2D(0,0);
}

void InputHandler::initialiseJoysticks()
{
	if(SDL_WasInit(SDL_INIT_JOYSTICK) == 0)
	{
		SDL_InitSubSystem(SDL_INIT_JOYSTICK);
	}

	if(SDL_NumJoysticks() > 0)
	{
		for(int i = 0; i < SDL_NumJoysticks(); i++)
		{
			SDL_Joystick* joy = SDL_JoystickOpen(i);
			if(joy)	//returns a null pointer on failure
			{
				//push new joy onto the vector, then assign empty value for it. 
				m_joysticks.push_back(joy);
				m_joystickValues.push_back(std::make_pair(new Vector2D(0,0),new Vector2D(0,0)));

				std::vector<bool> tempButtons; 

				for(int j = 0; j < SDL_JoystickNumButtons(joy); j++)
				{
					//initially push false back to buttons, as they're not pressed yet.
					tempButtons.push_back(false);
				}

				m_buttonStates.push_back(tempButtons);
			}
			else
			{
				std::cout << SDL_GetError();
			}
		}
		SDL_JoystickEventState(SDL_ENABLE);
		m_bJoysticksInitialised = true;

		std::cout << "Initialsed " << m_joysticks.size() << "joysticks";
	}
	else
	{
		m_bJoysticksInitialised = false;
	}
}

void InputHandler::clean()
{
	if(m_bJoysticksInitialised)
	{
		for(unsigned int i = 0; i < SDL_NumJoysticks();i++)
		{
			SDL_JoystickClose(m_joysticks[i]);
		}
	}
}

bool InputHandler::isKeyDown(SDL_Scancode key)
{
	if(m_keyStates != 0)
	{
		if(m_keyStates[key] == 1)
		{
			return true;
		}
	}

	return false;
}

void InputHandler::update()
{
	m_keyStates = SDL_GetKeyboardState(0);
	SDL_Event event;
	while(SDL_PollEvent(&event))
	{
		if(event.type == SDL_QUIT)
		{
			Game::instance()->quit();
		}

		if(event.type == SDL_JOYAXISMOTION)
		{
			int whichOne = event.jaxis.which;
			
			//left stick move left or right
			if(event.jaxis.value == 0)
			{
				if(event.jaxis.value > m_joystickDeadZone)
				{
					m_joystickValues[whichOne].first->setX(1);
				}
				else if (event.jaxis.value < -m_joystickDeadZone)
				{
					m_joystickValues[whichOne].first->setX(-1);
				}
				else
				{
					m_joystickValues[whichOne].first->setX(0);
				}
			}
			
			//left stick move up or down
			if(event.jaxis.value == 1)
			{
				if(event.jaxis.value > m_joystickDeadZone)
				{
					m_joystickValues[whichOne].first->setY(1);
				}
				else if (event.jaxis.value < -m_joystickDeadZone)
				{
					m_joystickValues[whichOne].first->setY(-1);
				}
				else
				{
					m_joystickValues[whichOne].first->setY(0);
				}
			}	

			//right stick move left or right
			if(event.jaxis.value == 2)
			{
				if(event.jaxis.value > m_joystickDeadZone)
				{
					m_joystickValues[whichOne].second->setX(1);
				}
				else if (event.jaxis.value < -m_joystickDeadZone)
				{
					m_joystickValues[whichOne].second->setX(-1);
				}
				else
				{
					m_joystickValues[whichOne].second->setX(0);
				}
			}

			//right stick move up or down
			if(event.jaxis.value == 3)
			{
				if(event.jaxis.value > m_joystickDeadZone)
				{
					m_joystickValues[whichOne].second->setY(1);
				}
				else if (event.jaxis.value < -m_joystickDeadZone)
				{
					m_joystickValues[whichOne].second->setY(-1);
				}
				else
				{
					m_joystickValues[whichOne].second->setY(0);
				}
			}				
		}

		if(event.type == SDL_JOYBUTTONDOWN)
		{
			int whichOne = event.jaxis.which;
			m_buttonStates[whichOne][event.jbutton.button] = true;
		}	

		if(event.type == SDL_JOYBUTTONUP)
		{
			int whichOne = event.jaxis.which; 
			m_buttonStates[whichOne][event.jbutton.button] = false;
		}

		if(event.type = SDL_MOUSEBUTTONDOWN)
		{
			if(event.button.button == SDL_BUTTON_LEFT)
			{
				// std::cout << "Left button down" << std::endl;
				m_mouseButtonStates[LEFT] = true; 
			}

			if(event.button.button == SDL_BUTTON_MIDDLE)
			{
				// std::cout << "Middle button down" << std::endl;
				m_mouseButtonStates[MIDDLE] = true;
			}

			if(event.button.button == SDL_BUTTON_RIGHT)
			{
				// std::cout << "Right button down" << std::endl;
				m_mouseButtonStates[RIGHT] = true;
			}
		} 

		if(event.type = SDL_MOUSEBUTTONUP)
		{
			if(event.button.button == SDL_BUTTON_LEFT)
			{
				// std::cout << "Left button up" << std::endl;
				m_mouseButtonStates[LEFT] = false; 
			}

			if(event.button.button == SDL_BUTTON_MIDDLE)
			{
				// std::cout << "Middle button up" << std::endl;
				m_mouseButtonStates[MIDDLE] = false;
			}

			if(event.button.button == SDL_BUTTON_RIGHT)
			{
				// std::cout << "Right button up" << std::endl;
				m_mouseButtonStates[RIGHT] = false;
			}
		}

		if(event.type = SDL_MOUSEMOTION)
		{
			m_mousePosition->setX(event.motion.x);
			m_mousePosition->setY(event.motion.y);
		}
	}
}

int InputHandler::xvalue(int joy, int stick)
{
	if(m_joystickValues.size() > 0)
	{
		if(stick == 1)
		{
			return m_joystickValues[joy].first->getX();
		}
		else if (stick == 2)
		{
			return m_joystickValues[joy].second->getX();
		}
	}
	return 0;
}

int InputHandler::yvalue(int joy, int stick)
{
	if(m_joystickValues.size() > 0)
	{
		if(stick == 1)
		{
			return m_joystickValues[joy].first->getY();
		}
		else if (stick == 2)
		{
			return m_joystickValues[joy].second->getY();
		}
	}
	return 0;
}

InputHandler* InputHandler::instance()
{
	if(s_pInstance == 0)
	{
		s_pInstance = new InputHandler();
		return s_pInstance;
	}

	return s_pInstance;
}

bool InputHandler::getButtonState(int joy, int buttonNumber)
{
	return m_buttonStates[joy][buttonNumber];
}

bool InputHandler::getMouseButtonState(int buttonNumber)
{
	return m_mouseButtonStates[buttonNumber];
}

Vector2D* InputHandler::getMousePosition()
{
	return m_mousePosition;
}