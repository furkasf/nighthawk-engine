#pragma once
#include"tinyxml/tinyxml.h"
#include"gameObject.h"
#include"GameObjectFactory.h"
#include"TextureManager.h"
#include<string>
#include<vector>

class StateParse
{
public:
	void parseState(const char* fileName, std::string stateID, std::vector<gameObject*> *object, std::vector<std::string> *textureIDS);

private:

	void parseTexture(TiXmlElement* TextureNode, std::vector<std::string> *textureIDS);
	void parseObject(TiXmlElement* ObjectNode, std::vector<gameObject*> *object);
};

