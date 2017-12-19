#include "LevelParser.h"

Level* LevelParser::parseLevel(const char* levelFile)
{
	//create a tinyxml doc. and load map xml 
	TiXmlDocument levelDocument; 
	levelDocument.LoadFile(levelFile);

	//create level objects
	Level* pLevel = new Level();

	//get root node. 
	TiXmlElement* pRoot = levelDocument.RootElement(); 

	pRoot->Attribute("titlewidth", &m_tileSize); 
	pRoot->Attribute("width", &m_width); 
	pRoot->Attribute("height", &m_height);

	// parse the tilesets
	for(TiXmlElement* e = pRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	{
		if(e->Value() == std::string("tileset"))
		{
			parseTilesets(e, pLevel->getTilesets());
		}
	}

	// parse any object layers

	for(TiXmlElement* e = pRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	{
		if(e->Value() == std::string("layer"))
		{
			parseTileLayer(e, pLevel->getLayers(), pLevel->getTilesets());
		}
	}

	return pLevel;
}

void LevelParser::parseTilesets(TiXmlElement* pTilesetRoot, std::vector<Tileset>* pTilesets)
{
	std::string srcImage = pTilesetRoot->FirstChildElement()->Attribute("source");
	std::string tilesetName = pTilesetRoot->Attribute("name");
	
	std::cout << "LevelParser::parseTilesets(): srcImage:    " << srcImage << std::endl;
	std::cout << "LevelParser::parseTilesets(): tilesetName: " << tilesetName << std::endl;

	// first add the tileset totexturemanager
	TheTextureManager::instance()->load(srcImage, tilesetName, TheGame::instance()->getRenderer());

	// Create Tileset Obj
	Tileset tileset; 
	pTilesetRoot->FirstChildElement()->Attribute("width", &tileset.width);
	pTilesetRoot->FirstChildElement()->Attribute("height", &tileset.height);
	pTilesetRoot->FirstChildElement()->Attribute("firstgid", &tileset.firstGridID);
	pTilesetRoot->FirstChildElement()->Attribute("tilewidth", &tileset.tileWidth);
	pTilesetRoot->FirstChildElement()->Attribute("tileheight", &tileset.tileHeight);
	pTilesetRoot->FirstChildElement()->Attribute("spacing", &tileset.spacing);
	pTilesetRoot->FirstChildElement()->Attribute("margin", &tileset.margin);

	tileset.name 	  = pTilesetRoot->Attribute("name");
	tileset.numColumns = tileset.width / (tileset.tileWidth + tileset.spacing);

	pTilesets->push_back(tileset);

	std::cout << "LevelParser::parseTilesets(): Pushed tileset onto vector" << std::endl;
}

void LevelParser::parseTileLayer(TiXmlElement* pTileElement, std::vector<Layer*> *pLayers, const std::vector<Tileset>* pTilesets)
{
	TileLayer* pTileLayer = new TileLayer(m_tileSize, *pTilesets);

	// tile data 
	std::vector<std::vector<int>> data;

	std::string decodedIDs;
	TiXmlElement* pDataNode; 

	for(TiXmlElement* e = pTileElement->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	{
		if(e->Value() == std::string("data"))
		{
			pDataNode = e; 
		}
	}

	for(TiXmlNode* e = pDataNode->FirstChild(); e != NULL; e = e->NextSibling())
	{
		TiXmlText* text = e->ToText(); 
		std::string t = text->Value();
		decodedIDs = base64_decode(t);
	}

	// uncompress zlib compression;

	uLongf numGids = m_width * m_height * sizeof(int);
	std::vector<unsigned> gids(numGids);
	uncompress((Bytef*)&gids[0],&numGids, (const Bytef*)decodedIDs.c_str(),decodedIDs.size());

	std::vector<int> layerRow(m_width);

	for(int j = 0; j < m_height; j++)
	{
		data.push_back(layerRow);
	}

	for(int rows = 0; rows < m_height; rows++)
	{
		for(int cols = 0; cols < m_width; cols++)
		{
			data[rows][cols] = gids[rows * m_width + cols];
		}
	}

	pTileLayer->setTileIDs(data);

	pLayers->push_back(pTileLayer); 
}