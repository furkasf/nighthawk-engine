#pragma once
#include "gameState.h"
#include "gameObject.h"
#include "menuState.h"
#include <vector>

class PauseState : public menuState
{
public:

    virtual void draw();
    virtual void update();

    virtual bool onEnter() override;
    virtual bool onExit() override;

    virtual std::string getStateID() const override;

    
private:

    static const std::string m_id;
    std::vector<gameObject*> m_gameObject;
    //we use manage pause menu behaviers with these callbacks
    static void onPause();
    static void exitPause();
    std::vector<int> callbackIDS;
    virtual void setCallbacks(const std::vector<callback>& callback) override;
};

