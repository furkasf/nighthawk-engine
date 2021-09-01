#pragma once
#include"BaseCreator.h"
#include<iostream>

class GameObjectFactory
{
public:

	static GameObjectFactory* instance();
	//register new object factory in m_creator
	bool RegisterFactory(std::string typeID, BaseCreator* factory);
	//creat object form m_creator by id(key)
	gameObject* CreatObject(std::string typeID);

private:
	virtual ~GameObjectFactory() {}
	static GameObjectFactory* m_instance;
	//this map hold to important element for our fatory funtion -- game objects 
	std::map<std::string, BaseCreator*> m_creators;
};

