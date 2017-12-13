#ifndef MENU_STATE_H
#define MENU_STATE_H
#include <vector>
#include "GameState.h"
#include "GameObject.h"

class MenuState : public GameState
{
protected: 
	typedef void(*Callback)();
	virtual void setCallbacks(const std::vector<Callback>& callbacks) = 0; 

	std::vector<Callback> m_callbacks;
};

#endif//MENU_STATE_H