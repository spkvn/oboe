//
// Created by kevin on 22/12/17.
//

#include "Unit.h"

Unit::Unit() : SDLGameObject()
{
    m_type = "Unit";
    m_moveRange = 0;
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
    SDLGameObject::update();
}
void Unit::clean()
{
    SDLGameObject::clean();
}

std::string Unit::getType() {return m_type;}
int Unit::getMoveRange() {return m_moveRange;}