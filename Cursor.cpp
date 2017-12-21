//
// Created by kevin on 21/12/17.
//

#include "Cursor.h"


Cursor::Cursor() : SDLGameObject()
{
    for(int i = 0; i < 4; i++)
    {
        keysPressed[i] = false;
    }
}

void Cursor::load(const LoaderParams *pParams)
{
    SDLGameObject::load(pParams);
    m_animSpeed = pParams->getAnimSpeed();
}

void Cursor::draw()
{
    SDLGameObject::draw();
}

void Cursor::update()
{
    handleInput();
    m_currentFrame = int(((SDL_GetTicks()/(1000/ m_animSpeed))%m_numFrames));
}

void Cursor::clean()
{

}

void Cursor::handleInput()
{
    if( (keysPressed[Direction::Left] && !(TheInputHandler::instance()->isKeyDown(SDL_SCANCODE_LEFT)))){
        keysPressed[Direction::Left] = false;
        int currentX = m_position.getX();
        if(currentX - 32 >= 0)
        {
            m_position.setX(currentX - 32);
        }
    }

    if(keysPressed[Direction::Right] && !(TheInputHandler::instance()->isKeyDown(SDL_SCANCODE_RIGHT)) ){
        keysPressed[Direction::Right] = false;
        int currentX = m_position.getX();
        if(currentX + 32 < TheGame::instance()->getGameWidth())
        {
            m_position.setX(currentX + 32);
        }
    }
    if(keysPressed[Direction::Up] && !(TheInputHandler::instance()->isKeyDown(SDL_SCANCODE_UP)) ){
        keysPressed[Direction::Up] = false;
        int currentY  = m_position.getY();
        if(currentY - 32 >= 0)
        {
            m_position.setY(currentY - 32);
        }
    }

    if(keysPressed[Direction::Down] && !(TheInputHandler::instance()->isKeyDown(SDL_SCANCODE_DOWN)) ){
        keysPressed[Direction::Down] = false;
        int currentY  = m_position.getY();
        if(currentY + 32 < TheGame::instance()->getGameHeight())
        {
            m_position.setY(currentY + 32);
        }
    }


    if(TheInputHandler::instance()->isKeyDown(SDL_SCANCODE_LEFT))
    {
        keysPressed[Direction::Left] = true;
    }

    if(TheInputHandler::instance()->isKeyDown(SDL_SCANCODE_RIGHT))
    {
        keysPressed[Direction::Right] = true;
    }

    if(TheInputHandler::instance()->isKeyDown(SDL_SCANCODE_UP))
    {
        keysPressed[Direction::Up] = true;

    }
    if(TheInputHandler::instance()->isKeyDown(SDL_SCANCODE_DOWN))
    {
        keysPressed[Direction::Down] = true;
    }
}