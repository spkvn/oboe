//
// Created by kevin on 22/12/17.
//

#include "Unit.h"

Unit::Unit() : SDLGameObject()
{
    m_type = "Unit";
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