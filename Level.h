#ifndef LEVEL_H
#define LEVEL_H

#include <string>
#include <vector>

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
	int numCoumns;
	std::string name;
};

class Level
{
public:
	Level();
	~Level();

	void update();
	void render();

	std::vector<Tileset>* getTilesets();
	std::vector<Layer*>* getLayers();
private:
	std::vector<Tileset> m_tilesets;
	std::vector<Layer*> m_layers;
};

#endif//LEVEL_H