#include "stateMachime.h"
#include<iostream>

void stateMachime::statePush(gameState* state)
{
	m_states.push_back(state);
	m_states.back()->onEnter();
}

void stateMachime::stateChange(gameState* state)
{
	if (!m_states.empty())
	{
		if (m_states.back()->onExit())
		{
			delete m_states.back();
			m_states.pop_back();
		}
	}

	m_states.push_back(state);
	m_states.back()->onEnter();
}

void stateMachime::popState()
{
	if (!m_states.empty())
	{
		delete m_states.back();
		m_states.pop_back();
	}
}

void stateMachime::draw()
{
	if (!m_states.empty())
	{
		m_states.back()->draw();
	}
}

void stateMachime::update()
{
	if (!m_states.empty())
	{
		m_states.back()->update();
	}
}