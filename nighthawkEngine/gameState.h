#pragma once
#include<string>
#include<vector>

class gameState
{
public:

	virtual ~gameState(){}
	void virtual draw() = 0;
	void virtual update() = 0;

	virtual std::string getStateID() const = 0;

	virtual bool onEnter() = 0;
	virtual bool onExit() = 0;

protected:
	std::vector<std::string> m_textureIDList;
};

