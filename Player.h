#ifndef PLAYER_H
#define PLAYER_H
#include "SDLGameObject.h"
#include "InputHandler.h"
class Player : public SDLGameObject
{
private:
	void handleInput();
public:
	Player(const LoaderParams* pParams);
	virtual void draw(); 
	virtual void update(); 
	virtual void clean();
};
#endif //PLAYER_H