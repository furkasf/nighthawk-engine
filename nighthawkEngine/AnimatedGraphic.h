#pragma once
#include "sdlGameObject.h"
class AnimatedGraphic : public sdlGameObject
{
public:

    AnimatedGraphic();
    virtual void draw() override;
    virtual void update() override;
    virtual void clean() override;
    virtual void load(const loadPrams* params) override;

private:
    int m_animSpeed;
};

