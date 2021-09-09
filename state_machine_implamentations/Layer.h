#pragma once
#include"vector2D.h"

class Layer
{
public:
	virtual void draw() = 0;
	virtual void update() = 0;
	
protected:
	virtual ~Layer(){}
};