#include "GameOverState.h"
#include"AnimatedGraphic.h"
#include"menuButton.h"
#include"mainMenuState.h"
#include"menuState.h"
#include"TextureManager.h"
#include"playerState.h"

const std::string GameOverState::m_id = "GAMEOVER";

std::string GameOverState::getStateID() const
{
	return m_id;
}

void GameOverState::draw()
{
	for (int i = 0; i < m_gameObject.size(); i++)
	{
		m_gameObject[i]->draw();
	}
}

void GameOverState::update()
{
	for (int i = 0; i < m_gameObject.size(); i++)
	{
		m_gameObject[i]->update();
	}
}

bool GameOverState::onEnter()
{
	StateParse parser;
	parser.parseState("test.xml", "GAMEOVER", &m_gameObject, &m_textureIDList);

	m_callback.push_back(0);
	m_callback.push_back(s_gameOverToMain);
	m_callback.push_back(s_restartPlay);
	return true;
}

bool GameOverState::onExit()
{
	for (int i = 0; i < m_textureIDList.size(); i++)
	{
		TextureManager::instance()->clearTextureMap(m_textureIDList[i]);
	}

	return true;
}

void GameOverState::s_gameOverToMain()
{
	Game::instance()->getStateMachine()->stateChange(new mainMenuState());
}

void GameOverState::s_restartPlay()
{
	Game::instance()->getStateMachine()->stateChange(new playerState());
}

void GameOverState::setCallbacks(const std::vector<callback>& callback)
{
	//go through the objects
	for (unsigned i = 0; i < m_gameObject.size(); i++) {
		//if they are of type MenuButton then assign a callback
		//based on the id passed in from the list
		if (dynamic_cast<menuButton*>(m_gameObject[i])) {
			menuButton* pButton = dynamic_cast<menuButton*>(m_gameObject[i]);
			pButton->setCallback(callback[pButton->getCallBackID()]);
		}
	}
}