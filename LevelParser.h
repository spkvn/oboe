#ifndef LEVEL_PARSER_H
#define LEVEL_PARSER_H

#include <vector>
#include <string>

#include "tinyxml.h"
#include "zlib.h"
#include "base64.h"

#include "Level.h"
#include "Layer.h"
#include "TileLayer.h"
#include "TextureManager.h"
#include "Game.h"

class LevelParser
{
public: 
	Level* parseLevel(const char* levelFile);
private:
	void parseTilesets(TiXmlElement* pTilesetRoot, std::vector<Tileset>* pTilesets);
	void parseTileLayer(TiXmlElement* pTileElement, std::vector<Layer*> *pLayers, const std::vector<Tileset>* pTilesets);

	int m_tileSize;
	int m_width; 
	int m_height;
};

#endif//LEVEL_PARSER_H