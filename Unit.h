//
// Created by kevin on 22/12/17.
//

#ifndef UNIT_H
#define UNIT_H

#include "SDLGameObject.h"

class Unit : public SDLGameObject
{
public:
    Unit();
    void load(const LoaderParams* pParams);

    virtual void draw();
    virtual void update();
    virtual void clean();
};

#endif //UNIT_H
