#include "mainMenuState.h"

#include "menuState.h"
#include"menuButton.h"
#include"playerState.h"

//give id to state to call cofrom state machine
const std::string mainMenuState::s_menuID = "MENU";

std::string mainMenuState::getStateID() const
{
	return s_menuID;
}

void mainMenuState::update()
{
	//update all menu item
	for (int i = 0; i < m_gameObject.size(); i++)
	{
		m_gameObject[i]->update();
	}
}

void mainMenuState::draw()
{
	//draw menu items in game object list
	for (int i = 0; i < m_gameObject.size(); i++)
	{
		m_gameObject[i]->draw();
	}
}

bool mainMenuState::onEnter()
{
	std::cout << "entered the menu state \n";
	
	StateParse parser;
	parser.parseState("test.xml", "MENU", &m_gameObject, &m_textureIDList);

	//push callbacks in callback vector from menuButton class
	m_callback.push_back(0);
	m_callback.push_back(exitFromMenu);
	m_callback.push_back(menuToPlay);

	//set callbacks
	setCallbacks(m_callback);

	return true;
}

bool mainMenuState::onExit()
{
	std::cout << "exited from current state\n";

	for (int i = 0; i < m_textureIDList.size(); i++)
	{
		TextureManager::instance()->clearTextureMap(m_textureIDList[i]);
	}

	m_gameObject.clear();
	
	TextureManager::instance()->clearTextureMap("exitButton");

	return true;
}

void mainMenuState::exitFromMenu()
{
	std::cout << "exit button is clicked \n";
	Game::instance()->closeGame();
}

void mainMenuState::menuToPlay()
{
	Game::instance()->getStateMachine()->stateChange(new playerState());
	std::cout << "play button is clicked \n";

}

void mainMenuState::setCallbacks(const std::vector<callback>& callback)
{
	for (int i = 0; i < m_gameObject.size(); i++)
	{
		if (menuButton* button = dynamic_cast<menuButton*>(m_gameObject[i]))
		{
			button->setCallback(callback[button->getCallBackID()]);
		}
		
	}
}