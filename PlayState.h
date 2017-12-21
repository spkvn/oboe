#ifndef PLAY_STATE_H
#define PLAY_STATE_H
#include <iostream>
#include <vector>
#include "GameState.h"
#include "StateParser.h"
#include "Level.h"
#include "LevelParser.h"

class PlayState : public GameState
{
public:
	virtual void update(); 	
	virtual void render(); 

	virtual bool onEnter(); 
	virtual bool onExit(); 

	virtual std::string getStateID() const { return s_playID;}
private:
	static const std::string s_playID; 

	std::vector<GameObject*> m_gameObjects;
};
#endif//PLAY_STATE_H