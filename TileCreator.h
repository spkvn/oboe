//
// Created by kevin on 21/12/17.
//

#ifndef OBOE_TILECREATOR_H
#define OBOE_TILECREATOR_H

#include "BaseCreator.h"
#include "Tile.h"

class TileCreator : public BaseCreator
{
    GameObject* createGameObject() const;
};


#endif //OBOE_TILECREATOR_H
