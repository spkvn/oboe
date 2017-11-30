#ifndef GAME_STATE_H
#define GAME_STATE_H
#include <string>

//Abstract Base Class.
class GameState
{
public:
	virtual void update()  = 0;
	virtual void render()  = 0; 

	virtual bool onEnter() = 0; //like load
	virtual bool onExit()  = 0;	//like clean

	virtual std::string getStateID() const = 0; 
};

#endif//GAME_STATE_H