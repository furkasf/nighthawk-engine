#include "LevelParser.h"
#include"TextureManager.h"
#include"TileLayer.h"
#include"base64/base64.h"
#include"zlib/zlib.h"
#include"zlib/zconf.h"

Level* LevelParser::parseLevel(const char* levelFile)
{
	//load leval xml file in a xml documant we extract informations from that documant
	TiXmlDocument levelDocumant;
	if (levelDocumant.LoadFile(levelFile) == false)
	{
		std::cout << "level document doesnt loaded \n";
		levelDocumant.Error();
	}
	
	//create a new level object
	Level* pLevel = new Level();

	//get root node
	TiXmlElement* pRoot = levelDocumant.RootElement();

	//get some attribute from root node
	pRoot->Attribute("tileSize", &m_tileSize);
	pRoot->Attribute("height", &m_height);
	pRoot->Attribute("width", &m_width);

	//parse the tileset
	for (TiXmlElement* e = pRoot->FirstChildElement(); e != nullptr; e = e->NextSiblingElement())
	{
		if (e->Value() == "tileset")
		{
			parseTilesets(e, pLevel->getTileset());
		}
	}

	//parse any object layer
	for (TiXmlElement* e = pRoot->FirstChildElement(); e != nullptr; e = e->NextSiblingElement())
	{
		if (e->Value() == "layer")
		{
			parseTileLayer(e, pLevel->getLayer(), pLevel->getTileset());
		}
	}
}

void LevelParser::parseTilesets(TiXmlElement* pTilesetRoot, std::vector<TileSet>* pTilesets)
{
	//first add the tileset to texture manager
	TextureManager::instance()->load(pTilesetRoot->FirstChildElement()->Attribute("source"), Game::instance()->get_renderer(), pTilesetRoot->Attribute("name"));

	//create a tileset object
	TileSet tileset;
	pTilesetRoot->FirstChildElement()->Attribute("width",
		&tileset.width);
	pTilesetRoot->FirstChildElement()->Attribute("height",
		&tileset.height);
	pTilesetRoot->Attribute("firstgid", &tileset.firstGridID);
	pTilesetRoot->Attribute("tilewidth", &tileset.tileWidth);
	pTilesetRoot->Attribute("tileheight", &tileset.tileHeight);
	pTilesetRoot->Attribute("spacing", &tileset.spacing);
	pTilesetRoot->Attribute("margin", &tileset.margin);
	tileset.name = pTilesetRoot->Attribute("name");
	tileset.numColumns = tileset.width / (tileset.tileWidth +
		tileset.spacing);
	pTilesets->push_back(tileset);
}
void LevelParser::parseTileLayer(TiXmlElement* pTileElement, std::vector<Layer*>* pLayers, const std::vector<TileSet>* pTilesets)
{
	
	TileLayer* pTilaeLayer = new TileLayer(m_tileSize, pTilesets);
	//tile data
	std::vector<std::vector<int>> data;

	std::string decodedIDs;
	TiXmlElement* pDataNode;

	//select to data node in xml file
	for (TiXmlElement* e = pDataNode->FirstChildElement(); e != nullptr; e = e->NextSiblingElement())
	{
		if (e->Value() == "data")
		{
			pDataNode = e;
		}
	}

	//decode selected node atribute
	for (TiXmlNode* e = pDataNode->FirstChild(); e != nullptr; e = e->NextSiblingElement())
	{
		TiXmlText* ptext = e->ToText();
		std::string text = ptext->Value();
		//decode the selected text
		decodedIDs = base64_decode(text);
	}

	//uncompress zib comprerssion
	uLongf numGids = m_width * m_height * sizeof(int);
	std::vector<unsigned> gids(numGids);
	uncompress((Bytef*)&gids[0], &numGids, (const Bytef*)decodedIDs.c_str(), decodedIDs.size());

	std::vector<int> layerRow(m_width);

	for (int j = 0; j < m_height; j++)
	{
		data.push_back(layerRow);
	}

	for (int rows = 0; rows < m_height; rows++)
	{
		for (int cols = 0; cols < m_width; cols++)
		{
			//data actual 2d vector
			data[rows][cols] = gids[rows * m_width + cols];
		}
	}

	pTilesets->setTileIDs(data);

	pLayers->push_back(pTilesets);
}

void LevelParser::parseObjectLayer(TiXmlElement* pObjectElement, std::vector<Layer*>* pLayers)
{
	// create an object layer
	ObjectLayer* pObjectLayer = new ObjectLayer();
	std::cout << pObjectElement->FirstChildElement()->Value();
	for (TiXmlElement* e = pObjectElement->FirstChildElement(); e !=
		NULL; e = e->NextSiblingElement())
	{
		std::cout << e->Value();
		if (e->Value() == std::string("object"))
		{
			int x, y, width, height, numFrames, callbackID, animSpeed;
			std::string textureID;
			// get the initial node values type, x and y
			e->Attribute("x", &x);
			e->Attribute("y", &y);
			gameObject* pGameObject =
				GameObjectFactory::instance()->create(e -> Attribute("type"));
			// get the property values
			for (TiXmlElement* properties = e->FirstChildElement(); properties != NULL; properties = properties -> NextSiblingElement())
			{
				if (properties->Value() == std::string("properties"))
				{
					for (TiXmlElement* property = properties -> FirstChildElement(); property != NULL; property = property -> NextSiblingElement())
					{
						if (property->Value() == std::string("property"))
						{
							if (property->Attribute("name") ==
								std::string("numFrames"))
							{
								property->Attribute("value", &numFrames);
							}
							else if (property->Attribute("name") ==
								std::string("textureHeight"))
							{
								property->Attribute("value", &height);
							}
							else if (property->Attribute("name") ==
								std::string("textureID"))
							{
								textureID = property->Attribute("value");
							}
							else if (property->Attribute("name") ==
								std::string("textureWidth"))
							{
								property->Attribute("value", &width);
							}
							else if (property->Attribute("name") ==
								std::string("callbackID"))
							{
								property->Attribute("value", &callbackID);
							}
							else if (e->Attribute("name") ==
								std::string("animSpeed"))
							{
								property->Attribute("value", &animSpeed);
							}
						}
					}
				}
			}
			pGameObject->load(new loadPrams(x, y, width, height, textureID, numFrames, callbackID, animSpeed));
			pObjectLayer->getGameObjects()->push_back(pGameObject);
		}
	}
	pLayers->push_back(pObjectLayer);
}

void LevelParser::parseTextures(TiXmlElement* pTextureRoot)
{
	TextureManager::instance()->load(pTextureRoot->Attribute("name"), Game::instance()->get_renderer(), pTextureRoot->Attribute("value"));
}