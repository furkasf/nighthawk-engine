#include "TileLayer.h"

TileLayer::TileLayer(int tileSize, std::vector<TileSet>& tileset) : m_tilesets{tileset}, m_tileSize{tileSize}
{

}

void TileLayer::draw()
{

}

void TileLayer::update()
{

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
	m_tileIDs = tileID;
}