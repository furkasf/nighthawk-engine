#pragma once
#include "BaseCreator.h"
#include"player.h"

class playerCreator : public BaseCreator
{
public:

	gameObject* createGameObject() const override
	{
		return new player();
	}

};


