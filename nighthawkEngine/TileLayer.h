#pragma once
#include"Level.h"

class TileLayer : public Layer
{
public:
	TileLayer(int tileSize, const std::vector<TileSet>& tileset);
	
	virtual void draw() override;
	virtual void update() override;

	void setTileIDS(const std::vector<std::vector<int>> &data);
	void settileSize(int tileSize);

	TileSet getTileSetByID(int tileID);
private:

	int m_numColumns;
	int m_numRows;
	int m_tileSize;

	vector2D m_position;
	vector2D m_velocity;

	const std::vector<TileSet>& m_tilesets;
	std::vector<std::vector<int>> m_tileIDs;
};

