#pragma once
#include"vector2D.h"
#include"sdlGameObject.h"
#include"input.h"

class player :
    public sdlGameObject
{
public:

    player();
    ~player()
    {
        std::cout << "player instance destructed \n";
    }

    virtual void update() override;
    virtual void draw() override;
    virtual void clean() override;
    virtual void load(const loadPrams* params) override;


private:
   
};

