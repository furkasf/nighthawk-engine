#pragma once
#include"Level.h"
#include"ObjectLayer.h"
#include"GameObjectFactory.h"
#include"loadPrams.h"
#include"tinyxml/tinyxml.h"

class LevelParser
{
public:
	Level* parseLevel(const char* levelFile);

private:
	void parseTilesets(TiXmlElement* pTilesetRoot,  std::vector<TileSet>* pTilesets);
	void parseTileLayer(TiXmlElement* pTileElement, std::vector<Layer*>* pLayers, const std::vector<TileSet>* pTilesets);
	void parseObjectLayer(TiXmlElement* pObjectElement, std::vector<Layer*>* pLayers);
	void parseTextures(TiXmlElement* pTextureRoot);
	int m_tileSize;
	int m_width;
	int m_height;
};

