#pragma once
#include "sdlGameObject.h"
class Enemy : public sdlGameObject
{
public:

    Enemy();

    virtual void draw() override;
    virtual void update() override;
    virtual void clean() override;
    virtual void load(const loadPrams* params) override;

};

