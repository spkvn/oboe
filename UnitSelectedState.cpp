//
// Created by kevin on 22/12/17.
//

#include "UnitSelectedState.h"

const std::string UnitSelectedState::s_UnitSelectedID = "UNITSELECTED";

UnitSelectedState::UnitSelectedState(std::vector<GameObject *> parentStateObjects, Unit* unit, TileGraph* t, Cursor* cursor)
{
    m_gameObjects = parentStateObjects;
    m_unit = unit;
    m_cursor = cursor;
    m_tileGraph = t;
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

    // find move range
    recurseMoveRange(m_unit->getPosition().getX(), m_unit->getPosition().getY(), 1);

    // find path from selected unit to each tile.
    m_tileGraph->calculatePath(m_unit->getPosition().getX(), m_unit->getPosition().getY());

    std::cout << "Entering Unit Selected State" << std::endl;
}

void UnitSelectedState::recurseMoveRange(int x, int y,int currentDistance)
{
    Tile* t = m_tileGraph->getTileAtXY(x/32,y/32);

    Tile* l = t->getLeft();
    Tile* r = t->getRight();
    Tile* u = t->getUp();
    Tile* d = t->getDown();

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

bool UnitSelectedState::onExit()
{
    //When a unit has been moved, attack? or finish, go back to previous state.
}

void UnitSelectedState::update()
{
    m_cursor->update(m_movableTiles);
    m_unit->update();

    if(TheInputHandler::instance()->isKeyDown(SDL_SCANCODE_C)) {
        TheGame::instance()->getStateMachine()->popState();
    }

    //if x, calculate path.
    if(TheInputHandler::instance()->isKeyDown(SDL_SCANCODE_X)){
        if(isMovePositionValid()){
            std::cout << "move is valid, move the unit to that xy" << std::endl;

            //get cursor xy
            int cursX = (int) m_cursor->getPosition().getX();
            int cursY = (int) m_cursor->getPosition().getY();

            //get unit xy
            int unitX = (int) m_unit->getPosition().getX();
            int unitY = (int) m_unit->getPosition().getY();

            //get tile at cursor xy.
            Tile* currentTile = m_tileGraph->getTileAtXY(cursX/32,cursY/32);
            std::stack<Tile*> positions;

            while(currentTile != nullptr)
            {
//                int currX = (int) currentTile->getPosition().getX();
//                int currY = (int) currentTile->getPosition().getY();
//
//                if( currX != unitX && currY != unitY)
//                {
                    positions.push(currentTile);
//                }

                currentTile = m_tileGraph->getPrevious(currentTile->getPosition().getX()/32, currentTile->getPosition().getY()/32);
            }

//            while(!positions.empty())
//            {
//                std::cout << "(x:"<<positions.top()->getPosition().getX()<<",y:"<<positions.top()->getPosition().getY()<<"),";
//                positions.pop();
//            }
//            std::cout << std::endl;
//
            m_unit->setMovePath(positions);

        }
    }
}

bool UnitSelectedState::isMovePositionValid()
{
    bool valid = false;

    int cursorX = m_cursor->getPosition().getX();
    int cursorY = m_cursor->getPosition().getY();

    for(int i = 0; i < m_movableTiles.size(); i++)
    {
        int tileX = m_movableTiles[i]->getPosition().getX();
        int tileY = m_movableTiles[i]->getPosition().getY();

        if( cursorX == tileX && tileY == cursorY){
            valid = true;
        }
    }

    return valid;
}

void UnitSelectedState::render()
{
    m_tileGraph->draw();

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

    if(isMovePositionValid()){
        m_tileGraph->drawPath(m_cursor->getPosition().getX(), m_cursor->getPosition().getY());
    }

    for(int i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->draw();
    }
}