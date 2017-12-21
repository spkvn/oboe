//
// Created by kevin on 22/12/17.
//

#ifndef OBOE_INFANTRY_H
#define OBOE_INFANTRY_H

#include "Unit.h"
//#include "SDLGameObject.h"

class Infantry : public Unit
{
public:
    Infantry();
    void load(const LoaderParams* pParams);

    virtual void draw();
    virtual void update();
    virtual void clean();
};


#endif //OBOE_INFANTRY_H
