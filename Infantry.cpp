//
// Created by kevin on 22/12/17.
//

#include "Infantry.h"

Infantry::Infantry() : Unit()
{}

void Infantry::load(const LoaderParams* pParams)
{
    Unit::load(pParams);
    m_type = "Infantry";
}

void Infantry::draw()
{
    Unit::draw();
}
void Infantry::update()
{
    Unit::update();
    m_currentFrame = int(((SDL_GetTicks()/(1000/1))%m_numFrames));
}
void Infantry::clean()
{
    Unit::clean();
}