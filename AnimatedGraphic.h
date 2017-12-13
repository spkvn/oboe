#ifndef ANIMATED_GRAPHIC_H
#define ANIMATED_GRAPHIC_H
#include "SDLGameObject.h"
#include "Vector2D.h"
#include "InputHandler.h"

class AnimatedGraphic : public SDLGameObject
{
public:
	AnimatedGraphic(const LoaderParams* pParams); 

	virtual void draw();
	virtual void update();
	virtual void clean();

	//function pointer, with 0 args, returning void;
	void (*m_callback)();
private:
	bool m_bReleased;
	int  m_animSpeed;
};

#endif//ANIMATED_GRAPHIC_H