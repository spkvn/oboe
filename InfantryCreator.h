//
// Created by kevin on 22/12/17.
//

#ifndef OBOE_INFANTRYCREATOR_H
#define OBOE_INFANTRYCREATOR_H

#include "BaseCreator.h"
#include "Infantry.h"

class InfantryCreator : public BaseCreator {
    GameObject* createGameObject() const;
};


#endif //OBOE_INFANTRYCREATOR_H
