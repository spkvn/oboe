//
// Created by kevin on 21/12/17.
//

#include "CursorCreator.h"

GameObject* CursorCreator::createGameObject() const
{
    return new Cursor();
}
