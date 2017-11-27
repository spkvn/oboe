#include "InputHandler.h"
#include "Game.h"

//allocating & initializing InputHandler pointer.
InputHandler* InputHandler::s_pInstance = 0;

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
				m_joysticks.push_back(joy);
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

void InputHandler::update()
{
	SDL_Event event;
	while(SDL_PollEvent(&event))
	{
		if(event.type == SDL_QUIT)
		{
			TheGame::instance()->quit();
		}
	}
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
