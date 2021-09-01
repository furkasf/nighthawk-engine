#pragma once
#include "gameState.h"
#include"gameObject.h"
#include"menuState.h"
#include<vector>

class GameOverState : public menuState
{

    virtual void update() override;
    virtual void draw() override;
    virtual bool onEnter() override;
    virtual bool onExit() override;
    //retun the state id
    virtual std::string getStateID() const override;

private:
    static const std::string m_id;
    std::vector<gameObject*> m_gameObject;

    //these statick functions use to callback after game over to return menu or restart game
    static void s_gameOverToMain();
    static void s_restartPlay();
	
    void setCallbacks(const std::vector<callback> &callback) override;
};

