//
// Created by kevin on 22/12/17.
//

#include "InfantryCreator.h"

GameObject* InfantryCreator::createGameObject() const
{
    return new Infantry();
}