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

    int getMovementCost(){return movementCost; }
    Tile* getLeft(){return pLeft; }
    Tile* getRight(){return pRight;}
    Tile* getUp(){return pUp;}
    Tile* getDown(){return pDown;}
    void setLeft(Tile* theTile){ pLeft = theTile; }
    void setRight(Tile* theTile){ pRight = theTile;}
    void setUp(Tile* theTile){ pUp = theTile;}
    void setDown(Tile* theTile){ pDown = theTile;}

private:
    Tile* pLeft;
    Tile* pRight;
    Tile* pUp;
    Tile* pDown;
    int movementCost;
};


#endif //TILE_H
