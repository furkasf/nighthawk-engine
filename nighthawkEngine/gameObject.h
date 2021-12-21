#pragma once
#include"loadPrams.h"

class gameObject
{
public:

	gameObject(){}

	virtual void draw() = 0;
	virtual void update() = 0;
	virtual void clean() = 0;
	virtual void load(const loadPrams* prams) = 0;

	virtual ~gameObject(){}
};