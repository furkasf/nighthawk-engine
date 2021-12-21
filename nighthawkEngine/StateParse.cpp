#include"StateParse.h"

void StateParse::parseState(const char* fileName, std::string stateID, std::vector<gameObject*>* object, std::vector<std::string>* textureIDS)
{
	//creat emty docmant to load xml file
	TiXmlDocument xmlDoc;

	//load xml file in documant
	if (xmlDoc.LoadFile(fileName) == false)
	{
		std::cerr << xmlDoc.ErrorDesc() << "\n";
		return ;
	}

	//get main node in xml file -- <states>
	TiXmlElement* root = xmlDoc.RootElement();
	//predeclare stareRoot -- <main>
	TiXmlElement* stateRoot = nullptr;

		for (TiXmlElement* e = root->FirstChildElement(); e != nullptr; e = e->NextSiblingElement())
		{
			if (e->Value() == stateID)
			{
				stateRoot = e;
			}
		}

	//predeclare textureNode
	TiXmlElement* textureNode = nullptr;

	//get texture node
	for (TiXmlElement* e = stateRoot->FirstChildElement(); e != nullptr; e = e->NextSiblingElement())
	{
		if (e->Value() == std::string("TEXTURES"))
		{
			textureNode = e;
		}
	}

	//parse texture node
	parseTexture(textureNode, textureIDS);

	//predeclare objectNode 
	TiXmlElement* objectNode = nullptr;

	//get object node from state node
	for (TiXmlElement* e = stateRoot->FirstChildElement(); e != nullptr; e = e->NextSiblingElement())
	{
		if (e->Value() == std::string("OBJECTS"))
		{
			objectNode = e;
		}
	}

	//parse object node
	parseObject(objectNode, object);
}


void StateParse::parseTexture(TiXmlElement* TextureNode, std::vector<std::string> *textureIDS)
{
	for (TiXmlElement* e = TextureNode->FirstChildElement(); e != nullptr; e = e->NextSiblingElement())
	{
		//get values from texture node
		std::string FileNameAttribute = e->Attribute("filename");
		std::string idAttribute = e->Attribute("ID");

		//we oush the texture id game state texture id vecctor for remove texture after exit from state
		textureIDS->push_back(idAttribute);

		//pash the parsed in formation texture manager load funtion to record texture to texture map(m_textureIDList)
		TextureManager::instance()->load(FileNameAttribute, Game::instance()->get_renderer(), idAttribute);
	}
}

void StateParse::parseObject(TiXmlElement* ObjectNode, std::vector<gameObject*>  *object)
{
	int x, y, width, height, numFrame, callbackID, animSpeed;
	std::string textureID;

		for (TiXmlElement* e = ObjectNode->FirstChildElement(); e != nullptr; e = e->NextSiblingElement())
	{
			//we cant grap int or float like data type from xml file, for get that values we need to manual get that value from xml file
			e->Attribute("x", &x);
			e->Attribute("y", &y);
			e->Attribute("width", &width);
			e->Attribute("height", &height);
			e->Attribute("numFrame", &numFrame);
			e->Attribute("callbackID", &callbackID);
			e->Attribute("animSpeed", &animSpeed);

			textureID = e->Attribute("textureID");

			//creay game object
			gameObject* gObject = GameObjectFactory::instance()->CreatObject(e->Attribute("type"));

			//load game object with parsed infornmations from object node
			gObject->load(new loadPrams(x, y, width, height, textureID, numFrame, callbackID, animSpeed));

			//that object vector represent to current state of state vector(m_gameObject)
			object->push_back(gObject);
		}
}

