#ifndef SDLGAMEOBJECT_H
#define SDLGAMEOBJECT_H
#include <SDL2/SDL.h>
#include "LoaderParams.h"
#include "GameObject.h"
#include "TextureManager.h"
#include "Vector2D.h"

class SDLGameObject : public GameObject
{
public: 
	SDLGameObject();
	virtual void draw();
	virtual void update(); 
	virtual void clean();

	void load( const LoaderParams* pParams );


	//Getters 
	Vector2D& getPosition() 	{return m_position;}
	int getWidth() 		    	{return m_width;}
	int getHeight()				{return m_height;}
	std::string getTextureID()  {return m_textureID;}
protected: 
	Vector2D m_position;
	Vector2D m_velocity;
	Vector2D m_acceleration;
	
	int m_width; 
	int m_height;
	int m_currentRow; 
	int m_currentFrame;
	int m_numFrames;
	std::string m_textureID;
};
#endif // SDLGAMEOBJECT_H