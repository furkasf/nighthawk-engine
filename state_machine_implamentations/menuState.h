#pragma once
#include "gameState.h"
#include"TextureManager.h"
#include"gameObject.h"
#include<iostream>


class menuState : public gameState
{
protected:
	//we degine callbacck type that represent void callbak
	typedef void (*callback)();
	virtual void setCallbacks(const std::vector<callback>& callback) = 0;
	std::vector<callback> m_callback;
};

