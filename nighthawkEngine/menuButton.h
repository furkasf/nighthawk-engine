#pragma once
#include "sdlGameObject.h"
class menuButton : public sdlGameObject
{
public:
	menuButton();
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;
	virtual void load(const loadPrams* params) override;
	void setCallback(void (*callback)());
	int getCallBackID();
	
private:
	enum button_state{MOUSE_OUT, MOUSE_OVER, CLICKED};
	void (*m_callback)();
	//we cheak button pressed or not
	bool m_bReleased;
	
};
