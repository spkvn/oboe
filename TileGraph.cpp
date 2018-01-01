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

TileGraph::TileGraph(std::vector<std::vector<Tile*>> tTiles)
{
    tiles=tTiles;
    mX = tiles.size();

    int largestY = 0;

    for(int i = 0; i < mX; i++)
    {
        if(tiles[i].size() > largestY){
            largestY = tiles[i].size();
        }
    }

    mY = largestY;
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

/* State of this function:
    I got confused following this: https://brilliant.org/wiki/dijkstras-short-path-finder/
    Try to follow along with this: https://www.geeksforgeeks.org/printing-paths-dijkstras-shortest-path-algorithm/

    In it's current state i have all the requisite parts ( i think ), i'm just a bit confused.
 */
void TileGraph::calculatePath(int srcX, int srcY, int destX, int destY)
{
//    std::cout << "calcuating graph"
//              << "\nsrcX:  " << srcX
//              << "\nsrcY:  " << srcY
//              << "\ndestX: " << destX
//              << "\ndestY: " << destY << std::endl;
    //effective infinity, as the max of an int.
    int infinity = std::numeric_limits<int>::max();

    //2D array of distances to tiles
    std::vector<std::vector<int>> distances;

    //vector of tiles which have not yet been visited & assessed.
    std::vector<Tile*> unvisited;

    //for every tile in graph.
    for(int x = 0; x < tiles.size(); x++ )
    {
        for(int y = 0; y < tiles[x].size(); y++)
        {
            //get it's x/y values
            int iterX = tiles[x][y]->getPosition().getX();
            int iterY = tiles[x][y]->getPosition().getY();

            //if xy matches source xy, 0, otherwise infinity.
            if(iterX != srcX && iterY != srcY){
                distances[x][y] = infinity;
            }else{
                //this is the source, distance set to 0;
                distances[x][y] = 0;
            }

            //unvisited starts with all tiles initally.
            unvisited.push_back(tiles[x][y]);
        }
    }

    while(!unvisited.empty())
    {
        Tile* v;
        int lowest = infinity;
        //Find the tile with lowest distance.
        for(int x = 0; x < tiles.size(); x++ )
        {
            for(int y = 0; y < tiles[x].size(); y++)
            {
                if(getTileAtXY(x,y)->getMovementCost() < lowest)
                {
                    //set the new lowest
                    lowest = getTileAtXY(x,y)->getMovementCost();

                    //move tile into v,
                    v = tiles[x][y];

                    //remove from unvisited
                    auto removeIfMatches = std::remove_if(unvisited.begin(), unvisited.end(),[x,y](Tile* t){
                        return (t->getPosition().getX() == x && t->getPosition().getY() == y);
                    });

                    unvisited.erase(removeIfMatches, unvisited.end());
                }
            }
        }

        //for each neighbour of v
        std::vector<Tile*> vNeighbours;
        vNeighbours.push_back(v->getLeft());
        vNeighbours.push_back(v->getDown());
        vNeighbours.push_back(v->getRight());
        vNeighbours.push_back(v->getUp());

        auto removeIfHasBeenVisited = std::remove_if(vNeighbours.begin(),vNeighbours.end(),[unvisited](Tile* neighbour){
            bool existsInUnvisited = false;
            for(int i = 0; i < unvisited.size(); i++)
            {
                if(unvisited[i]->getPosition().getX() == neighbour->getPosition().getX() &&)
                   unvisited[i]->getPosition().getY() == neighbour->getPosition().getY()){
                    existsInUnvisited = true;
                }
            }
            return existsInUnvisited;
        });

        //remove any tiles from neighbours if they have already been visited.
        vNeighbours.erase(removeIfHasBeenVisited, vNeighbours.end());



    }
}

