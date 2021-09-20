#include "TileLayer.h"
#include"Game.h"
#include"TextureManager.h"

TileLayer::TileLayer(int tileSize, std::vector<TileSet>& tileset) : m_tilesets{tileset}, m_tileSize{tileSize}, m_position(0, 0), m_velocity(0, 0)
{
	//we get screan area for fit  tiles on screan
	m_numColumns = Game::instance()->getGameWith() / m_tileSize;
	m_numRows = Game::instance()->getGameHeight() / m_tileSize;
}

void TileLayer::draw()
{
	//were is the all magic is happen
	int x1, y1, x2, y2 = 0;

	x1 = m_position.get_x() / m_tileSize;
	y1 = m_position.get_y() / m_tileSize;

	x2 = int(m_position.get_x()) % m_tileSize;
	y2 = int(m_position.get_y()) % m_tileSize;

	//write 2d loop or callback funtion to draw entire tile maps(each layer)
	for (int i = 0; i < m_numRows; i++)
	{
		for (int j = 0; j < m_numColumns; j++)
		{
			int id = m_tileIDs[i][j + x1]; //hold each tile in map in tile maps for in each iteration -- hold curent tile id
			if (id == 0)
			{
				continue;
			}

			TileSet tileset = getTileSetByID(id);

			//draw tilesets
			TextureManager::instance()->drawTile(tileset.name, tileset.margin, tileset.spacing, (j * m_tileSize) - x2, (i * m_tileSize) - y2, m_tileSize, m_tileSize,
				(id - (tileset.firstGridID - 1)) / tileset.numColumns, (id - (tileset.firstGridID - 1)) % tileset.numColumns, Game::instance()->get_renderer());
		}
	}
}

void TileLayer::update()
{
	//we set our map position on screan with using velocity
	m_position += m_velocity;
	m_velocity.set_x(1);
}

void TileLayer::setTileIDS(std::vector<int>& datas)
{
	
}

void TileLayer::settileSize(int tileSize)
{
	m_tileSize = tileSize;
}

TileSet TileLayer::getTileSetByID(int tileID)
{
	//compress each tileset's firstdid value and return the correnct tile set
	for (int i = 0; i < m_tilesets.size(); i++)
	{
		if (i + 1 <= m_tilesets.size() - 1)
		{
			if (tileID >= m_tilesets[i].firstGridID && tileID < m_tilesets[i + 1].firstGridID)
			{
				return m_tilesets[i];
			}
			else
			{
				return m_tilesets[i];
			}
		}
	}
	std::cout << "did not find tileset, returning empty tileset\n";
	TileSet t;
	return t;
}