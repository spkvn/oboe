#ifndef LEVEL_H
#define LEVEL_H

#include <string>
#include <vector>
#include <iostream>

#include "Layer.h"

struct Tileset
{
	int firstGridID;
	int tileWidth;
	int tileHeight; 
	int spacing; 
	int margin;
	int width; 
	int height;
	int numColumns;
	std::string name;
};

class Level
{
public:
	~Level();

	void update();
	void render();

	std::vector<Tileset>* getTilesets();
	std::vector<Layer*>* getLayers();
private:
	std::vector<Tileset> m_tilesets;
	std::vector<Layer*> m_layers;
	
	friend class LevelParser;	// Friend class makes class available to the friend (incl private parts)
								// I.E LevelParse can access Level ctor. 
	Level();
};

#endif//LEVEL_H