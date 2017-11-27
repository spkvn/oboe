#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include <SDL2/SDL.h>
#include <vector>
#include <iostream>

class InputHandler
{
public: 
	static InputHandler* instance();

	void update();
	void clean();

	void initialiseJoysticks();
	bool joysticksInitialised(){ return m_bJoysticksInitialised; }
private:
	InputHandler(); 
	~InputHandler() {}

	static InputHandler* s_pInstance;

	std::vector<SDL_Joystick*> m_joysticks;
	bool m_bJoysticksInitialised;
};

//defining singleton
typedef InputHandler TheInputHandler;

#endif //INPUT_HANDLER_H