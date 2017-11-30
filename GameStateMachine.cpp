#include "GameStateMachine.h"

void GameStateMachine::pushState(GameState* pState)
{
	//push & enter the state
	m_gameStates.push_back(pState);
	m_gameStates.back()->onEnter();
}

void GameStateMachine::popState()
{
	if(!(m_gameStates.empty()) &&
	     m_gameStates.back()->onExit())
	{
		//free the GameState point in vector.
		delete m_gameStates.back();

		//lose it from vector
		m_gameStates.pop_back();
	}
}

void GameStateMachine::changeState(GameState* pState)
{
	if(!m_gameStates.empty())
	{
		//Trying to enter state x from state x?
		if(m_gameStates.back()->getStateID() == pState->getStateID())
		{
			return ;// don't do anything, end function.
		}

		//if we can exit, pop it and free the pointer.
		if(m_gameStates.back()->onExit())
		{
			delete m_gameStates.back();
			m_gameStates.pop_back();
		}
	}

	//push back our new state.
	m_gameStates.push_back(pState);

	//enter that state
	m_gameStates.back()->onEnter();
}