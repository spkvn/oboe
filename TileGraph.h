//
// Created by kevin on 25/12/17.
//

#ifndef OBOE_TILEGRAPH_H
#define OBOE_TILEGRAPH_H

#include <vector>
#include <limits>
#include <algorithm>
#include "Tile.h"

class TileGraph
{
public:
    //create.
    TileGraph(int gameWidth, int gameHeight);
    TileGraph(std::vector<std::vector<Tile*>> tTiles);

    //get the tiles.
    Tile* getTileAtXY(int x, int y);
    void calculatePath(int srcX, int srcY, int destX, int destY);

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
