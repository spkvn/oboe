//
// Created by kevin on 25/12/17.
//

#include "TileGraph.h"

TileGraph::TileGraph(int gameWidth, int gameHeight)
{
    m_pathsCalculated = false;
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
    for(int x = 0; x <= mX; x++)
    {
        for(int y = 0; y <= mY; y++ )
        {
            Tile* t = tiles[x][y];

            //using getTileAtXY will allow us to set null on borders.
            t->setLeft(getTileAtXY(x-1,y));
            t->setRight(getTileAtXY(x+1,y));
            t->setUp(getTileAtXY(x,y-1));
            t->setDown(getTileAtXY(x,y+1));
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

void TileGraph::drawPath(int destX, int destY)
{
    Tile* dest = getTileAtXY(destX/32, destY/32);
    while(dest != nullptr)
    {
        int dX = dest->getPosition().getX();
        int dY = dest->getPosition().getY();

        TheTextureManager::instance()->draw(
                "aVertical",
                dX,
                dY,
                32,
                32,
                TheGame::instance()->getRenderer(),
                SDL_FLIP_NONE
        );
        dest = previousTiles[dX/32][dY/32];
    }
}

void TileGraph::update()
{

}

void TileGraph::calculatePath(int srcX, int srcY)
{
    //effective infinity, as the max of an int.
    int infinity = std::numeric_limits<int>::max();

    //2D array of distances to tiles
    std::vector<std::vector<int>> distances;

    //2D array of previous nodes.
    std::vector<std::vector<Tile*>> previous;

    //vector of tiles which have not yet been visited & assessed.
    std::vector<Tile*> unvisited;

    //resize previous to match tiles
    previous.resize(tiles.size());
    distances.resize(tiles.size());

    //for every tile in graph.
    for(int x = 0; x < tiles.size(); x++ )
    {
        //resize previous to match tiles.
        previous[x].resize(tiles[x].size());
        distances[x].resize(tiles[x].size());

        for(int y = 0; y < tiles[x].size(); y++)
        {
            //get it's x/y values
            int iterX = tiles[x][y]->getPosition().getX();
            int iterY = tiles[x][y]->getPosition().getY();

            //if xy matches source xy, 0, otherwise infinity.
            if(iterX != srcX || iterY != srcY){
                distances[x][y] = infinity;
            }else{
                //this is the source, distance set to 0;
                distances[x][y] = 0;
            }

            //previous array initialized to undefined.
            previous[x][y] = nullptr;

            //unvisited starts with all tiles initally.
            unvisited.push_back(tiles[x][y]);
        }
    }

    while(!unvisited.empty())
    {
        Tile* v;
        int lowest = infinity;

        //Find the tile in unvisited with lowest distance.
        for(int x = 0; x < tiles.size(); x++ )
        {
            for(int y = 0; y < tiles[x].size(); y++)
            {
                if(distances[x][y] < lowest)
                {
                    //if is not in unvisited, skip?
                    auto it = std::find_if(unvisited.begin(), unvisited.end(),[x,y](Tile* t){
                        if(t == NULL){
                            return false;
                        } else{
                            return (t->getPosition().getY()/32 == y && t->getPosition().getX()/32 == x);
                        }
                    });

                    if(it != unvisited.end()){
                        //set the new lowest
                        lowest = distances[x][y];

                        //move tile into v,
                        v = tiles[x][y];
                    }


                }
            }
        }


        // x and y index of v
        int vX = v->getPosition().getX();
        int vY = v->getPosition().getY();

        //remove from unvisited
        auto removeIfMatches = std::remove_if(unvisited.begin(), unvisited.end(), [vX, vY](Tile *t) {
            bool match = (t->getPosition().getX() == vX && t->getPosition().getY() == vY);
            return match;
        });

        unvisited.erase(removeIfMatches, unvisited.end());

        vX = vX/32;
        vY = vY/32;

        //for each neighbour of v
        std::vector<Tile*> vNeighbours;
        vNeighbours.push_back(v->getLeft());
        vNeighbours.push_back(v->getDown());
        vNeighbours.push_back(v->getRight());
        vNeighbours.push_back(v->getUp());

        auto removeIfHasBeenVisited = std::remove_if(vNeighbours.begin(),vNeighbours.end(),[unvisited](Tile* neighbour){
            bool existsInUnvisited = false;

            if(neighbour == NULL){
                return false;
            }

            for(int i = 0; i < unvisited.size(); i++)
            {
                if(unvisited[i]->getPosition().getX() == neighbour->getPosition().getX() &&
                   unvisited[i]->getPosition().getY() == neighbour->getPosition().getY()){
                    existsInUnvisited = true;
                }
            }

            //returning not exists, since if its in there we do not want to remove it from vector.
            return ! existsInUnvisited;
        });

        //remove any tiles from neighbours if they have already been visited.
        vNeighbours.erase(removeIfHasBeenVisited, vNeighbours.end());

        // for each neighbour of v
        for(int i = 0; i < vNeighbours.size(); i++)
        {
            if(vNeighbours[i] == NULL)
            {
                continue;
            }

            // x and y position of v's current neighbour.
            int vNX = vNeighbours[i]->getPosition().getX()/32;
            int vNY = vNeighbours[i]->getPosition().getY()/32;

            //get distance of
            int alt = distances[vX][vY] + vNeighbours[i]->getMovementCost();

            if(alt < distances[vNX][vNY])
            {
                distances[vNX][vNY] = alt;
                previous[vNX][vNY] = v;
            }
        }
    }

    std::cout << "End of dijsktra: Here's the path from destxy to sourcexy" << std::endl;

    m_pathsCalculated = true;
    previousTiles = previous;


//    Tile* dest = getTileAtXY(destX/32,destY/32);
//    while(dest != nullptr)
//    {
//        int diX = dest->getPosition().getX()/32;
//        int diY = dest->getPosition().getY()/32;
//
//        std::cout << ",(" << diX << "," << diY << ")";
//        dest = previous[diX][diY];
//    }
//    std::cout << ";" << std::endl;
}

