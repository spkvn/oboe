//
// Created by kevin on 21/12/17.
//

#ifndef OBOE_CURSORCREATOR_H
#define OBOE_CURSORCREATOR_H

#include "Cursor.h"
#include "BaseCreator.h"
#include "InputHandler.h"


class CursorCreator : public BaseCreator
{
public:
    GameObject* createGameObject() const;
};


#endif //OBOE_CURSORCREATOR_H
