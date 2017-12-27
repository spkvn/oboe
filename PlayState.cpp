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
        enterUnitSelectedState(v);
    }
}

void PlayState::enterUnitSelectedState(std::vector<SDLGameObject*> v)
{
    for(int i = 0; i < v.size(); i++)
    {
        std::string type = v[i]->getType();
        if(type == "Infantry" || type == "Unit"){
            Unit* u = dynamic_cast<Unit*>(v[i]);
            Cursor* c = dynamic_cast<Cursor*>(m_pCursor);
            TheGame::instance()->getStateMachine()->pushState(
                    new UnitSelectedState(m_gameObjects,u,m_tileGraph,c));
        }
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
    m_tileGraph->draw();
	for(int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}

bool PlayState::onEnter()
{
    // Parse XML File (contains units and cursor)
	StateParser stateParser;
	stateParser.parseState("../conf/oboePlay.xml", s_playID, &m_gameObjects, &m_textureIDList);

    // create the tileGraph.
    m_tileGraph = new TileGraph(TheGame::instance()->getGameWidth(), TheGame::instance()->getGameHeight());

    // TODO: find a more efficient way of storing the cursor. (probably don't even need it in XML)
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