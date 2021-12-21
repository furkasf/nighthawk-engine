#pragma once
#include "BaseCreator.h"
#include"Enemy.h"

class enemyCreator : public BaseCreator
{
public:

	gameObject* createGameObject() const override
	{
		return new Enemy();
	}

};