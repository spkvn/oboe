//
// Created by kevin on 21/12/17.
//

#ifndef CURSOR_H
#define CURSOR_H

#include <iostream>

#include "SDLGameObject.h"
#include "InputHandler.h"
#include "Game.h"

class Tile;

class Cursor : public SDLGameObject
{
public:
    Cursor();
    void load(const LoaderParams* pParams);

    virtual void draw();
    virtual void update();
    virtual void update(std::vector<Tile*> m_movableTiles);
    virtual void clean();

    int getX();
    int getY();

private:
    void handleInput();
    void handleInputWhileSelected();
    enum Direction {Left = 0, Up = 1, Right = 2, Down = 3};
    bool keysPressed[4];
    int m_animSpeed;
};


#endif //CURSOR_H
