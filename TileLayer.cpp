#include "TileLayer.h"

TileLayer::TileLayer(int tileSize, const std::vector<Tileset> &tilesets) 
		: m_tileSize(tileSize),m_position(0,0), m_velocity(0,0), m_tilesets(tilesets)
{
	m_numColumns = (TheGame::instance()->getGameWidth() / m_tileSize);
	m_numRows = (TheGame::instance()->getGameHeight() / m_tileSize);
}
	
void TileLayer::update()
{
	m_position += m_velocity;
}

void TileLayer::render()
{
	std::cout << "TilerLayer::render(): start of render." << std::endl;
	std::cout << "TilerLayer::render(): m_tileSize:  " << m_tileSize << std::endl;
	std::cout << "TileLayer::render(): m_numRows:    " << m_numRows << std::endl;
	std::cout << "TileLayer::render(): m_numColumns: " << m_numColumns << std::endl;
	int x,y,x2,y2 = 0; 

	x = m_position.getX() / m_tileSize;
	y = m_position.getY() / m_tileSize;

	x2 = int(m_position.getX()) % m_tileSize; 
	y2 = int(m_position.getY()) % m_tileSize;


	std::cout << "TilerLayer::render(): Examining x/y coords" << std::endl;
	std::cout << "TilerLayer::render(): x:  " << x << std::endl;
	std::cout << "TilerLayer::render(): y:  " << y << std::endl;
	std::cout << "TilerLayer::render(): x2: " << x2 << std::endl;
	std::cout << "TilerLayer::render(): y2: " << y2 << std::endl;


	std::cout << "TilerLayer::render(): entering drawing for loop." << std::endl;
	for(int i = 0; i < m_numRows; i++)
	{
		std::cout << "TilerLayer::render(): \tRow: " << i << std::endl;
		for(int j = 0; j < m_numColumns; j++)	
		{

			// std::cout << "TilerLayer::render(): \t id = m_tileIDs["<<i+y<<"]["<<j+x<<"]" << std::endl;			
			int id = m_tileIDs[i + y][j+x];
			if(id==0)
			{

				// std::cout << "TilerLayer::render(): \tskipping at m_tileIDs["<<i<<"]["<<j+x<<"]" << std::endl;
				continue;
			}
			std::cout << "TilerLayer::render(): \tColumn:" << j << std::endl;

			// std::cout << "TilerLayer::render(): \t getting tileset by id with param of  "<< id << std::endl;
			Tileset tileset = getTilesetByID(id); 


			id--;
			
			// std::cout << "TilerLayer::render(): \tAbout to draw tile with params: " << std::endl;

			// std::cout << "TilerLayer::render(): \t\tID:           " << tileset.name << std::endl;
			// std::cout << "TilerLayer::render(): \t\tID exists:    " << TheTextureManager::instance()->textureExists(tileset.name) << std::endl;
			// std::cout << "TilerLayer::render(): \t\tMargin:       " << tileset.margin << std::endl;
			// std::cout << "TilerLayer::render(): \t\tSpacing:      " << tileset.spacing << std::endl;
			// std::cout << "TilerLayer::render(): \t\tX:            " << (j*m_tileSize) - x2 << std::endl;
			// std::cout << "TilerLayer::render(): \t\tY:            " << (i * m_tileSize) - y2 << std::endl;
			// std::cout << "TilerLayer::render(): \t\tWidth:        " << m_tileSize << std::endl;
			// std::cout << "TilerLayer::render(): \t\tHeight:       " << m_tileSize << std::endl;
			// std::cout << "TilerLayer::render(): \t\tcurrentRow:   " << (id - (tileset.firstGridID - 1)) / tileset.numColumns << std::endl;
			// std::cout << "TilerLayer::render(): \t\tcurrentFrame: " << (id - (tileset.firstGridID - 1)) % tileset.numColumns<< std::endl;
			std::cout << "TileLayer::render(): \t\tDrawing tile at x,y of " << (j * m_tileSize) - x2 << "," << (i * m_tileSize) - y2 << std::endl;
			TheTextureManager::instance()->drawTile(
				tileset.name,
				tileset.margin,
				tileset.spacing,
				(j * m_tileSize) - x2,
				(i * m_tileSize) - y2,
				m_tileSize, 
				m_tileSize, 
				(id - (tileset.firstGridID - 1)) / tileset.numColumns,
				(id - (tileset.firstGridID - 1)) % tileset.numColumns, 
				TheGame::instance()->getRenderer() 
			);
			
			std::cout << "TileLayer::render(): \t\tFinished drawing tile at " << (j * m_tileSize) - x2 << "," << (i * m_tileSize) - y2 << std::endl;
		}
	}
}

void TileLayer::setTileIDs(const std::vector<std::vector<int>>& data)
{
	m_tileIDs = data;
}

void TileLayer::setTileSize(int tileSize)
{
	m_tileSize = tileSize;
}

Tileset TileLayer::getTilesetByID(int tileID)
{
	for(int i = 0; i <= m_tilesets.size(); i++)
	{
		if( i + 1 <= m_tilesets.size() - 1)
		{
			if(tileID >= m_tilesets[i].firstGridID && tileID < m_tilesets[i + 1].firstGridID)
			{
				return m_tilesets[i];
			}
		}
		else
		{
			return m_tilesets[i];
		}
	}

	std::cout << "Did not find tileset of gid " << tileID << ". Returning empty tileset." << std::endl;

	Tileset t; 
	return t;
}