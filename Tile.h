//
// Created by kevin on 21/12/17.
//

#ifndef TILE_H
#define TILE_H

#include <string>

#include "SDLGameObject.h"
#include "InputHandler.h"

class Tile : public SDLGameObject
{
public:
    Tile();
    void load(const LoaderParams* pParams);

    virtual void draw();
    virtual void update();
    virtual void clean();
};


#endif //OBOE_TILE_H
