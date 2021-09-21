#pragma once
#include"Layer.h"
#include"gameObject.h"
#include<vector>

class ObjectLayer : Layer
{
public:

	virtual void update() override
	{
		for (int i = 0; i < m_gameObjects.size(); i++)
		{
			m_gameObjects[i]->update();
		}
	}

	virtual void draw() override
	{
		for (int i = 0; i < m_gameObjects.size(); i++)
		{
			m_gameObjects[i]->draw();
		}
	}

	std::vector<gameObject*>* getGameObjects()
	{
		return &m_gameObjects;
	}

private:
	std::vector<gameObject*> m_gameObjects;
};