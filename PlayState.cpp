#include "PlayState.h"

const std::string PlayState::s_playID = "PLAY";  

void PlayState::update()
{
	for(int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}

    if(InputHandler::instance()->isKeyDown(SDL_SCANCODE_X)) {
		std::vector<SDLGameObject*> v = getObjectsAtCursor();
    }
}

std::vector<SDLGameObject*> PlayState::getObjectsAtCursor()
{
	int cursorX, cursorY;
	cursorX = m_pCursor->getPosition().getX();
	cursorY = m_pCursor->getPosition().getY();
	std::vector<SDLGameObject*> v;
	for(int i = 0; i < m_gameObjects.size(); i++)
	{
		SDLGameObject* objectI  = dynamic_cast<SDLGameObject*>(m_gameObjects[i]);
		if(objectI->getPosition().getX() == cursorX && objectI->getPosition().getY() == cursorY && objectI->getType() != "Cursor")
		{
			std::cout << "Adding an object: " << objectI->getType() << std::endl;
			v.push_back(objectI);
		}
	}

    return v;
}

void PlayState::render()
{
	for(int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}

bool PlayState::onEnter()
{
	StateParser stateParser;
	stateParser.parseState("../conf/oboePlay.xml", s_playID, &m_gameObjects, &m_textureIDList);

    for(int i = 0; i < m_gameObjects.size(); i++)
    {
        SDLGameObject* SDLGameObjI =  dynamic_cast<SDLGameObject*>(m_gameObjects[i]);
        if(SDLGameObjI->getType() == "Cursor")
        {
            std::cout << "PlayState::onEnter(): Found Cursor" << std::endl;
            m_pCursor = SDLGameObjI;
        }
    }

    std::cout << "entering PlayState" << std::endl;
	return true;
}

bool PlayState::onExit()
{
	for(int i = 0; i < m_gameObjects.size(); i++ )
	{
		m_gameObjects[i]->clean();
	}

	m_gameObjects.clear();

	//clear texture manager.
	for(int i = 0; i < m_textureIDList.size(); i++)
	{
		TheTextureManager::instance()->clearFromTextureMap(m_textureIDList[i]);
	}

	std::cout << "exiting PlayState" << std::endl;
	return true;
}