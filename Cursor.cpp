//
// Created by kevin on 21/12/17.
//

#include "Cursor.h"


Cursor::Cursor() : SDLGameObject()
{

}

void Cursor::load(const LoaderParams *pParams)
{
    SDLGameObject::load(pParams);
}

void Cursor::draw()
{
    SDLGameObject::draw();
}

void Cursor::update()
{
    handleInput();
}

void Cursor::clean()
{

}

void Cursor::handleInput()
{
    if(TheInputHandler::instance()->isKeyDown(SDL_SCANCODE_LEFT))
    {
        int currentX = m_position.getX();
        std::cout << "Left Key down" << std::endl;
        if(currentX - 1 * 32 >= 0)
        {
            m_position.setX(currentX - 1 * 32);
            std::cout << "Cursor::handleInput(): Moving Left ("<<m_position.getX()<<","<<m_position.getY()<<")"<<std::endl;
        }
    }

    if(TheInputHandler::instance()->isKeyDown(SDL_SCANCODE_RIGHT))
    {
        int currentX = m_position.getX();
        std::cout << "Right Key down" << std::endl;
        if(currentX + 1 * 32 < TheGame::instance()->getGameWidth())
        {
            m_position.setX(currentX + 1 * 32);
            std::cout << "Cursor::handleInput(): Moving Right (x,y): ("<<m_position.getX()<<","<<m_position.getY()<<")"<<std::endl;
            std::cout << "Cursor::handleInput(): Moving Right gameWidth:" << TheGame::instance()->getGameWidth() << std::endl;
        }
    }

    if(TheInputHandler::instance()->isKeyDown(SDL_SCANCODE_UP))
    {
        int currentY  = m_position.getY();
        std::cout << "Up Key down" << std::endl;
        if(currentY - 1 * 32 >= 0)
        {
            m_position.setY(currentY - 1 * 32);
            std::cout << "Cursor::handleInput(): Moving Up ("<<m_position.getX()<<","<<m_position.getY()<<")"<<std::endl;
        }
    }
    if(TheInputHandler::instance()->isKeyDown(SDL_SCANCODE_DOWN))
    {
        int currentY  = m_position.getY();
        std::cout << "Down Key down" << std::endl;
        if(currentY + 1 * 32 < TheGame::instance()->getGameHeight())
        {
            m_position.setY(currentY + 1 * 32);
            std::cout << "Cursor::handleInput(): Moving Down ("<<m_position.getX()<<","<<m_position.getY()<<")"<<std::endl;
            std::cout << "Cursor::handleInput(): Moving Down gameHeight:" << TheGame::instance()->getGameHeight() << std::endl;
        }
    }
}