#include "PauseState.h"
#include "menuButton.h"
#include"StateParse.h"
#include"mainMenuState.h"
#include"menuState.h"
#include"playerState.h"
#include"TextureManager.h"

const std::string PauseState::m_id = "PAUSE";

std::string PauseState::getStateID() const
{
	return m_id;
}

void PauseState::draw()
{
	for (int i = 0 ; i < m_gameObject.size(); i++)
	{
		m_gameObject[i]->draw();
	}
}

void PauseState::update()
{
	for (int i = 0; i < m_gameObject.size(); i++)
	{
		m_gameObject[i]->update();
	}
}

bool PauseState::onEnter()
{
	StateParse parser;
	parser.parseState("test.xml", "PAUSE", &m_gameObject, &m_textureIDList);
	m_callback.push_back(0);
	m_callback.push_back(onPause);
	m_callback.push_back(exitPause);
	
	setCallbacks(m_callback);
	return true;
}

bool PauseState::onExit()
{
	for (int i = 0; i < m_textureIDList.size(); i++)
	{
		TextureManager::instance()->clearTextureMap(m_textureIDList[i]);
	}
	return true;
}

void PauseState::onPause()
{
	Game::instance()->getStateMachine()->popState();
}

void PauseState::exitPause()
{
	Game::instance()->getStateMachine()->stateChange(new mainMenuState());
}

void PauseState::setCallbacks(const std::vector<callback>& callback)
{
	for (unsigned i = 0; i < m_gameObject.size(); i++)
	{
		//if they are of type MenuButton then assign a callback
		//based on the id passed in from the list
		if (dynamic_cast<menuButton*>(m_gameObject[i]))
		{
			menuButton* pButton = dynamic_cast<menuButton*>(m_gameObject[i]);
			pButton->setCallback(callback[pButton->getCallBackID()]);
		}
	}
}