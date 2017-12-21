//
// Created by kevin on 21/12/17.
//

#include "Tile.h"

Tile::Tile() : SDLGameObject()
{
}

void Tile::load(const LoaderParams *pParams)
{
    SDLGameObject::load(pParams);
}


void Tile::draw()
{
    TheTextureManager::instance()->draw(
        m_textureID,
        (int) m_position.getX(),
        (int) m_position.getY(),
        m_width,
        m_height,
        TheGame::instance()->getRenderer()
    );
}

void Tile::update()
{
    //doesn't really need to take input.
}

void Tile::clean()
{
    SDLGameObject::clean();
}