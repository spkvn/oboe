//
// Created by kevin on 22/12/17.
//

#include "UnitSelectedState.h"

const std::string UnitSelectedState::s_UnitSelectedID = "UNITSELECTED";

UnitSelectedState::UnitSelectedState(std::vector<GameObject *> parentStateObjects, Unit* unit)
{
    m_gameObjects = parentStateObjects;
    m_unit = unit;
}

bool UnitSelectedState::onEnter()
{
    // Load transparent Texture.
    TheTextureManager::instance()->load("../assets/moveable.png","movable", TheGame::instance()->getRenderer());

    // Load ArrowCursor images.
    TheTextureManager::instance()->load("../assets/arrows/aEndDown.png",     "aEndDown", TheGame::instance()->getRenderer());
    TheTextureManager::instance()->load("../assets/arrows/aEndUp.png",       "aEndUp", TheGame::instance()->getRenderer());
    TheTextureManager::instance()->load("../assets/arrows/aEndLeft.png",     "aEndLeft", TheGame::instance()->getRenderer());
    TheTextureManager::instance()->load("../assets/arrows/aEndRight.png",    "aEndRight", TheGame::instance()->getRenderer());
    TheTextureManager::instance()->load("../assets/arrows/aLeft.png",        "aLeft", TheGame::instance()->getRenderer());
    TheTextureManager::instance()->load("../assets/arrows/aRight.png",       "aRight", TheGame::instance()->getRenderer());
    TheTextureManager::instance()->load("../assets/arrows/aUp.png",          "aUp", TheGame::instance()->getRenderer());
    TheTextureManager::instance()->load("../assets/arrows/aDown.png",        "aDown", TheGame::instance()->getRenderer());
    TheTextureManager::instance()->load("../assets/arrows/aVertical.png",    "aVertical", TheGame::instance()->getRenderer());
    TheTextureManager::instance()->load("../assets/arrows/aHorizontal.png",  "aHorizontal", TheGame::instance()->getRenderer());

    recurseMoveRange(m_unit->getPosition().getX(), m_unit->getPosition().getY(), 1);

    std::cout << "Entering Unit Selected State" << std::endl;
}

void UnitSelectedState::recurseMoveRange(int x, int y,int currentDistance)
{
    Tile* l = tileLeft(x,y);
    if(l != NULL && currentDistance < m_unit->getMoveRange())
    {
        int lX = l->getPosition().getX();
        int lY = l->getPosition().getY();
        if(lX != m_unit->getPosition().getX() || lY != m_unit->getPosition().getY())
        {
            std::cout << "Adding tile at x: "<< lX << "y: " << lY << std::endl;
            m_movableTiles.push_back(l);
            recurseMoveRange(l->getPosition().getX(), l->getPosition().getY(), currentDistance+1);
        }
    }

    Tile* r = tileRight(x,y);
    if(r != NULL && currentDistance < m_unit->getMoveRange())
    {
        int rX = r->getPosition().getX();
        int rY = r->getPosition().getY();
        if(rX != m_unit->getPosition().getX() || rY != m_unit->getPosition().getY())
        {
            std::cout << "Adding tile at x: "<< rX << "y: " << rY << std::endl;
            m_movableTiles.push_back(r);
            recurseMoveRange(r->getPosition().getX(), r->getPosition().getY(), currentDistance+1);
        }
    }

    Tile* u = tileUp(x,y);
    if(u != NULL && currentDistance < m_unit->getMoveRange())
    {
        int uX = u->getPosition().getX();
        int uY = u->getPosition().getY();
        if(uX != m_unit->getPosition().getX() || uY != m_unit->getPosition().getY())
        {
            std::cout << "Adding tile at x: "<< uX << "y: " << uY << std::endl;
            m_movableTiles.push_back(u);
            recurseMoveRange(u->getPosition().getX(), u->getPosition().getY(), currentDistance+1);
        }
    }

    Tile* d = tileDown(x,y);
    if(d != NULL && currentDistance < m_unit->getMoveRange())
    {
        int dX = d->getPosition().getX();
        int dY = d->getPosition().getY();
        if(dX != m_unit->getPosition().getX() || dY != m_unit->getPosition().getY())
        {
            std::cout << "Adding tile at x: "<< dX << "y: " << dY << std::endl;
            m_movableTiles.push_back(d);
            recurseMoveRange(d->getPosition().getX(), d->getPosition().getY(), currentDistance+1);
        }
    }
}

bool UnitSelectedState::inMovables(Tile* tile)
{
    for(int i = 0; i < m_movableTiles.size(); i++)
    {
        if( m_movableTiles[i]->getPosition().getX() == tile->getPosition().getX()
        &&  m_movableTiles[i]->getPosition().getY() == tile->getPosition().getY())
        {
            return true;
        }
    }
    return false;
}

Tile* UnitSelectedState::tileLeft(int x, int y)
{
    for(int i = 0 ; i < m_gameObjects.size(); i++)
    {
        SDLGameObject* obj = dynamic_cast<SDLGameObject*>(m_gameObjects[i]);
        if(obj->getPosition().getX() == x - 32)
        {
            if(obj->getPosition().getY() == y )
            {
                if (obj->getType() == "Tile")
                {
                    return (Tile*)obj;
                }
            }
        }
    }
    return NULL;
}

Tile* UnitSelectedState::tileRight(int x, int y)
{
    for(int i = 0 ; i < m_gameObjects.size(); i++)
    {
        SDLGameObject* obj = dynamic_cast<SDLGameObject*>(m_gameObjects[i]);
        if(obj->getPosition().getX() == x + 32)
        {
            if(obj->getPosition().getY() == y )
            {
                if (obj->getType() == "Tile")
                {
                    return (Tile*)obj;
                }
            }
        }
    }
    return NULL;
}

Tile* UnitSelectedState::tileUp(int x, int y)
{
    for(int i = 0 ; i < m_gameObjects.size(); i++)
    {
        SDLGameObject* obj = dynamic_cast<SDLGameObject*>(m_gameObjects[i]);
        if(obj->getPosition().getY() == y - 32)
        {
            if(obj->getPosition().getX() == x )
            {
                if (obj->getType() == "Tile")
                {
                    return (Tile*)obj;
                }
            }
        }
    }
    return NULL;
}


Tile* UnitSelectedState::tileDown(int x, int y)
{
    for(int i = 0 ; i < m_gameObjects.size(); i++)
    {
        SDLGameObject* obj = dynamic_cast<SDLGameObject*>(m_gameObjects[i]);
        if(obj->getPosition().getY() == y + 32)
        {
            if(obj->getPosition().getX() == x )
            {
                if (obj->getType() == "Tile")
                {
                    return (Tile*)obj;
                }
            }
        }
    }
    return NULL;
}

bool UnitSelectedState::onExit()
{
    //When a unit has been moved, attack? or finish, go back to previous state.
}

void UnitSelectedState::update()
{
    //Check for updownleftright again, see draw path based on that.

    //if x, move unit and enter attack state

    //if y, popState
}

void UnitSelectedState::render()
{
    for(int i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->draw();
    }

    for(int i = 0; i < m_movableTiles.size(); i++)
    {
        TheTextureManager::instance()->draw(
                "movable",
                m_movableTiles[i]->getPosition().getX(),
                m_movableTiles[i]->getPosition().getY(),
                32,
                32,
                TheGame::instance()->getRenderer(),
                SDL_FLIP_NONE
        );
    }
}