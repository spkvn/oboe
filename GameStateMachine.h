#ifndef GAME_STATE_MACHINE_H
#define GAME_STATE_MACHINE_H

#include <vector>

#include "GameState.h"

class GameStateMachine 
{
public:
	void pushState(GameState* pState); 
	void changeState(GameState* pState);
	void popState();
private:
	std::vector<GameState*> m_gameStates; 
};

#endif//GAME_STATE_MACHINE_H