//
// Created by kevin on 22/12/17.
//

#ifndef UNIT_H
#define UNIT_H

#include <stack>

#include "SDLGameObject.h"

class Tile;

class Unit : public SDLGameObject
{
public:
    Unit();
    void load(const LoaderParams* pParams);

    virtual void draw();
    virtual void update();
    virtual void clean();

    std::string getType();
    int getMoveRange();

    void setMovePath(std::stack<Tile*> movePath);

protected:
    void moveToPathElement();

    int m_moveRange;
    std::stack<Tile*> m_movePath;
    bool m_movePathSet;
};

#endif //UNIT_H
