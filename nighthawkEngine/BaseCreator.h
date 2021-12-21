#pragma once
#include"gameObject.h"
#include<string>
#include<map>

class BaseCreator
{
public:
	virtual gameObject* createGameObject() const = 0;
	virtual ~BaseCreator() = default;
};

