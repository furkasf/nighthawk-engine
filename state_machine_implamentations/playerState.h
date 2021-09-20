#pragma once
#include "gameState.h"
#include"playerCreator.h"
#include"StateParse.h"
#include"gameObject.h"
#include"sdlGameObject.h"
#include"LevelParser.h"

class playerState :
    public gameState
{
public:
    virtual void update() override;
    virtual void draw() override;
    virtual bool onEnter() override;
    virtual bool onExit() override;
    bool cheackCollision(sdlGameObject* p1, sdlGameObject* p2);
    //retun the state id
    virtual std::string getStateID() const override;

private:
   static const std::string s_player;
   //we get the player\s information and set player from here
   std::vector <gameObject*> m_gameObject;
   Level* pLevel;
};

