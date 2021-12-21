#include "GameObjectFactory.h"

GameObjectFactory* GameObjectFactory::m_instance = nullptr;

GameObjectFactory* GameObjectFactory::instance()
{
	if (m_instance == nullptr)
	{
		m_instance = new GameObjectFactory();
		return m_instance;
	}

	return m_instance;
}

bool GameObjectFactory::RegisterFactory(std::string typeID, BaseCreator* factory)
{
	//save factory in temporart map
	auto it = m_creators.find(typeID);

	//cheack if that factory registered in map if is , delete passed map
	if (it != m_creators.end())
	{
		delete factory;
		return false;
	}

	m_creators[typeID] = factory;
	return true;
}

gameObject* GameObjectFactory::CreatObject(std::string typeID)
{
	auto it = m_creators.find(typeID);

	if (it == m_creators.end())
	{
		std::cout << "this factor doesnt registred on fatory table \n";
		return nullptr;
	}

	BaseCreator* factory = (*it).second;
	return factory->createGameObject();

}