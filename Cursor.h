//
// Created by kevin on 21/12/17.
//

#ifndef CURSOR_H
#define CURSOR_H

#include <iostream>

#include "SDLGameObject.h"
#include "InputHandler.h"
#include "Game.h"


class Cursor : public SDLGameObject
{
public:
    Cursor();
    void load(const LoaderParams* pParams);

    virtual void draw();
    virtual void update();
    virtual void clean();

private:
    void handleInput();
    enum Direction {Left = 0, Up = 1, Right = 2, Down = 3};
    bool keysPressed[4];
};


#endif //CURSOR_H
