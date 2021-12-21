#pragma once
#include"BaseCreator.h"
#include"AnimatedGraphic.h"

class animatedGraphicCreator : public BaseCreator
{
public:
	gameObject* createGameObject() const override
	{
		return new AnimatedGraphic();
	}
};