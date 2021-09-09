#include "Level.h"

void Level::draw()
{
	if (!m_layers.empty())
	{
		//draw all layer from layer vector
		for (int i = 0; i < m_layers.size(); i++)
		{
			m_layers[i]->draw();
		}
	}
}

void Level::update()
{
	if (!m_layers.empty())
	{
		//update all layer from layer vector
		for (int i = 0; i < m_layers.size(); i++)
		{
			m_layers[i]->update();
		}
	}
}

std::vector<TileSet>* Level::getTileset()
{
	return &m_tileSets;
}

std::vector<Layer*>* Level::getLayer()
{
	return &m_layers;
}