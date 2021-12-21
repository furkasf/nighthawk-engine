#pragma once
#include "menuState.h"
#include"StateParse.h"

class mainMenuState : public menuState
{
public:

    virtual void update() override;
    virtual void draw() override;
    virtual bool onEnter() override;
    virtual bool onExit() override;
    //retun the state id
    virtual std::string  getStateID() const  override;
private:
    static const std::string s_menuID;
    virtual void setCallbacks(const std::vector<callback>& callback) override;
    //which use to store menu items
    std::vector <gameObject*> m_gameObject;
    //callback funtion for memu items
    static void menuToPlay();
    static void exitFromMenu();

};

