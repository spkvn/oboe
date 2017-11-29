#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include <SDL2/SDL.h>
#include <vector>
#include <utility>
#include <iostream>

#include "Game.h"

enum mouse_buttons
{
	LEFT = 0,
	MIDDLE = 1, 
	RIGHT = 2,
};

class InputHandler
{
public: 
	static InputHandler* instance();

	void update();
	void clean();

	int xvalue(int joy, int stick);
	int yvalue(int joy, int stick);

	//Joystick Functions
	void initialiseJoysticks();
	bool joysticksInitialised(){ return m_bJoysticksInitialised;}

	// JoyStick Button functions
	bool getButtonState(int joy, int buttonNumber);

	// Mouse Button functions
	bool getMouseButtonState(int buttonNumber);
private:
	InputHandler();
	~InputHandler() {}

	static InputHandler* s_pInstance;

	//Mouse Button Vars
	std::vector<bool> m_mouseButtonStates; 

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