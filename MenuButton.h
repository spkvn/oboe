#ifndef MENU_BUTTON_H
#define MENU_BUTTON_H
#include "SDLGameObject.h"
#include "Vector2D.h"
#include "InputHandler.h"

class MenuButton : public SDLGameObject
{
public:
	MenuButton(const LoaderParams* pParams, void (*callback)()); 

	virtual void draw();
	virtual void update();
	virtual void clean();

	//function pointer, with 0 args, returning void;
	void (*m_callback)();
private:
	enum button_state
	{
		MOUSE_OUT = 2, 
		MOUSE_OVER = 1, 
		CLICKED = 0
	};

	bool m_bReleased;
};

#endif//MENU_BUTTON_H