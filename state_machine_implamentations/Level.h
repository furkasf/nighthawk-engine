#pragma once
#include"Layer.h"
#include"LevelParser.h"
#include<vector>
#include<string>

struct TileSet
{
	int firstGridID;
	int tileWidth;
	int tileHeight;
	int spacing;
	int margin;
	int width;
	int height;
	int numColumns;
	std::string name;
};

class Level
{
public:
	//draw and update fuctions for tile sets
	virtual void draw();
	virtual void update();
	//that getter funtion will return pointer of tileset vector
	std::vector<TileSet>* getTileset();
	std::vector<Layer*>* getLayer();
protected:
	//store tile sets informatio here
	std::vector<TileSet> m_tileSets;
	std::vector<Layer*> m_layers;
	//level class freind to level parser class
	friend class LevelParser;
	Level(){}
};

