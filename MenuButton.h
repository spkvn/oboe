#ifndef MENU_BUTTON_H
#define MENU_BUTTON_H
#include "SDLGameObject.h"
#include "Vector2D.h"
#include "InputHandler.h"

class MenuButton : public SDLGameObject
{
public:
	MenuButton(const LoaderParams* pParams); 

	virtual void draw();
	virtual void update();
	virtual void clean();
private:
	enum button_state
	{
		MOUSE_OUT = 2, 
		MOUSE_OVER = 1, 
		CLICKED = 0
	};
};

#endif//MENU_BUTTON_H