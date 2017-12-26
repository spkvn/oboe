//
// Created by kevin on 25/12/17.
//

#ifndef OBOE_TILEGRAPH_H
#define OBOE_TILEGRAPH_H

#include <vector>
#include "Tile.h"

class TileGraph
{
public:
    //create.
    TileGraph(int gameWidth, int gameHeight);

    //get the tiles.
    Tile* getTileAtXY(int x, int y);

    void draw();
    void update();
private:

    //2D vector to store the tile grid.
    std::vector<std::vector<Tile*>> tiles;

    // x and y of tilegraph.
    int mX;
    int mY;
};


#endif //OBOE_TILEGRAPH_H
