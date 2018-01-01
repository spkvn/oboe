//
// Created by kevin on 22/12/17.
//

#ifndef OBOE_UNITSELECTEDSTATE_H
#define OBOE_UNITSELECTEDSTATE_H

#include "GameState.h"
#include "Game.h"

class Tile;
class Cursor;
class TileGraph;

class UnitSelectedState : public GameState
{
public:
    UnitSelectedState(std::vector<GameObject*> parentStateObjects, Unit* unit, TileGraph* t, Cursor* cursor);
    virtual void update();
    virtual void render();

    virtual bool onEnter();
    virtual bool onExit();

    virtual std::string getStateID() const {return s_UnitSelectedID;}
private:
    static const std::string s_UnitSelectedID;
    Unit* m_unit;
    Cursor* m_cursor;
    TileGraph* m_tileGraph;

    std::vector<SDLGameObject*> m_movePath;
    std::vector<GameObject*> m_gameObjects;
    std::vector<Tile*> m_movableTiles;

    void recurseMoveRange(int x, int y, int currentDistance);
    bool isMovePositionValid();
};


#endif //OBOE_UNITSELECTEDSTATE_H
