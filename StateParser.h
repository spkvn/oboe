#ifndef STATE_PARSER_H
#define STATE_PARSER_H
#include <iostream> 
#include <vector> 
#include <string>
#include "tinyxml.h"
#include "GameObjectFactory.h"
#include "GameObject.h"
#include "TextureManager.h"
#include "Game.h"

class StateParser
{
public:
	bool parseState(const char* stateFile, std::string stateID, std::vector<GameObject*> *pObjects, std::vector<std::string> *pTextureIDs);
private:
	void parseObjects(TiXmlElement* pStateRoot, std::vector<GameObject*> *pObjects);
	void parseTextures(TiXmlElement* pStateRoot, std::vector<std::string> *pTextureIDs);
};
#endif//STATE_PARSER_H