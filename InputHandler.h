#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include <SDL2/SDL.h>
#include <vector>
#include <utility>
#include <iostream>

#include "Game.h"

class InputHandler
{
public: 
	static InputHandler* instance();

	void update();
	void clean();

	//Joystick Functions
	void initialiseJoysticks();
	bool joysticksInitialised(){ return m_bJoysticksInitialised;}

	int xvalue(int joy, int stick);
	int yvalue(int joy, int stick);

	bool getButtonState(int joy, int buttonNumber);
private:
	InputHandler() {} 
	~InputHandler() {}

	static InputHandler* s_pInstance;

	//Joystick Vars
	std::vector<SDL_Joystick*> m_joysticks;
	std::vector<std::pair<Vector2D*, Vector2D*>> m_joystickValues;
	bool m_bJoysticksInitialised;
	const int m_joystickDeadZone = 10000;

	//JoyStick button Vars 
	std::vector<std::vector<bool>> m_buttonStates; 
};

//defining singleton
typedef InputHandler TheInputHandler;

#endif //INPUT_HANDLER_H