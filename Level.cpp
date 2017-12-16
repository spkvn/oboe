#include "Level.h"

std::vector<Tileset>* Level::getTilesets()
{
	return &m_tilesets;
}

std::vector<Layer*>* Level::getLayers()
{
	return &m_layers;
}