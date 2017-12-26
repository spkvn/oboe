//
// Created by kevin on 25/12/17.
//

#include "TileGraph.h"

TileGraph::TileGraph(int gameWidth, int gameHeight)
{
    // 32 is tile size.
    mX = gameWidth/32;
    mY = gameHeight/32;

    // set the size of X vector
    tiles.resize(mX);

    //place all tiles
    for(int x = 0; x < mX; x++)
    {
        //set size of y vector
        tiles[x].resize(mY);

        for(int y = 0; y < mY; y++ )
        {
            Tile* t = new Tile();
            t->load(new LoaderParams(x*32,y*32,32,32,"grass",0));
            tiles[x][y] = t;
        }
    }

    // if mX == 20, then our vector will be 0..19. will get segfaults if we leave that be. 
    mX--;
    mY--;

    //set all ajacent tiles.
    for(int x = 0; x < mX; x++)
    {
        for(int y = 0; y < mY; y++ )
        {
            Tile* t = tiles[x][y];

            //using getTileAtXY will allow us to set null on borders.
            t->setLeft(getTileAtXY(x-1,y));
            t->setRight(getTileAtXY(x+1,y));
            t->setUp(getTileAtXY(x,y-1));
            t->setDown(tiles[x][y+1]);
        }
    }

}

Tile* TileGraph::getTileAtXY(int x, int y)
{
    if(!(x > mX || x < 0) && !(y > mY || y < 0))
    {
        return tiles[x][y];
    } else {
        return NULL;
    }
}

void TileGraph::draw()
{
    for(int x = 0; x <= mX; x++)
    {
        for(int y = 0; y <= mY; y++ )
        {
            tiles[x][y]->draw();
        }
    }
}

void TileGraph::update()
{

}