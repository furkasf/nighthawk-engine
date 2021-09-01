#pragma once
#include"gameState.h"
#include<vector>

class stateMachime
{
public:

	void statePush(gameState* state);
	void stateChange(gameState* state);
	void popState();

	void draw();
	void update();

private:
	std::vector<gameState*> m_states;
};

