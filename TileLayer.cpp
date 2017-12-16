#include "TileLayer.h"

TileLayer::TileLayer(int tileSize, const std::vector<Tileset> &tilesets) : m_position(0,0), m_velocity(0,0), m_tilesets(tilesets)
{
}
	
void TileLayer::update()
{

}

void TileLayer::render()
{

}

void TileLayer::setTileIDs(const std::vector<std::vector<int>>& data)
{

}

void TileLayer::setTileSize(int tileSize)
{

}

Tileset TileLayer::getTilesetByID(int tileID)
{

}