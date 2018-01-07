//
// Created by kevin on 22/12/17.
//

#include "Unit.h"

//This is bad. But I can't seem to include from Unit.h file.
#include "Tile.h"

Unit::Unit() : SDLGameObject()
{
    m_type = "Unit";
    m_moveRange = 0;
    m_movePathSet = false;
}

void Unit::load(const LoaderParams* pParams)
{
    SDLGameObject::load(pParams);
}

void Unit::draw()
{
    SDLGameObject::draw();
}
void Unit::update()
{
    if(m_movePathSet)
    {
        moveToPathElement();
    }
    SDLGameObject::update();
}
void Unit::clean()
{
    SDLGameObject::clean();
}

std::string Unit::getType() {return m_type;}
int Unit::getMoveRange() {return m_moveRange;}

void Unit::setMovePath(std::stack<Tile *> movePath)
{
    m_movePath = movePath;
    m_movePathSet = true;
}

void Unit::moveToPathElement()
{
    int nX = (int)m_movePath.top()->getPosition().getX();
    int nY = (int)m_movePath.top()->getPosition().getY();
    int cX = (int)m_position.getX();
    int cY = (int)m_position.getY();

    if(nX > cX) //next is right
    {
        m_velocity += Vector2D(0.1,0);
//        std::cout << "moving " << m_type << " right"  << std::endl;
    }
    else if (nX < cX) // next is left
    {
        m_velocity += Vector2D(-0.1,0);
//        std::cout << "moving " << m_type << " left"  << std::endl;
    }
    else if( nY > cY) //next is down
    {
        m_velocity += Vector2D(0,0.1);
//        std::cout << "moving " << m_type << " down"  << std::endl;
    }
    else if (nY < cY) //next is up
    {
        m_velocity += Vector2D(0,-0.1);
//        std::cout << "moving " << m_type << " up"  << std::endl;
    }

    if(nX == cX && nY == cY)
    {
        std::cout << "unit moved to next, popping from stack " << std::endl;
        m_velocity = Vector2D(0,0);
        m_movePath.pop();
    }

    if(m_movePath.empty())
    {
        m_movePathSet = false;
    }
}