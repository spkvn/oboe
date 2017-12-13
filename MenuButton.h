#ifndef MENU_BUTTON_H
#define MENU_BUTTON_H
#include "SDLGameObject.h"
#include "Vector2D.h"
#include "InputHandler.h"
#include "LoaderParams.h"

class MenuButton : public SDLGameObject
{
public:
	MenuButton(); 

	virtual void draw();
	virtual void update();
	virtual void clean();
	void 		 load(const LoaderParams* pParams); 

	void setCallback(void(*callback)()) {m_callback = callback;}
	int getCallbackID() { return m_callbackID;}
private:
	enum button_state
	{
		MOUSE_OUT = 2, 
		MOUSE_OVER = 1, 
		CLICKED = 0
	};
	bool m_bReleased;
	int m_callbackID;
	void (*m_callback)();  //function pointer, with 0 args, returning void;
};

#endif//MENU_BUTTON_H