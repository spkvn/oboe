//
// Created by kevin on 21/12/17.
//

#include "TileCreator.h"

GameObject* TileCreator::createGameObject() const
{
    return new Tile();
}
