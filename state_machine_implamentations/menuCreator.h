#pragma once
#include "BaseCreator.h"
#include "menuButton.h"


class menuCreator : public BaseCreator
{
public:
	gameObject* createGameObject() const override
	{
		return new menuButton();
	}
};