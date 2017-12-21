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
    SDLGameObject::draw();
}

void Tile::update()
{
    //doesn't really need to take input.
}

void Tile::clean()
{
}