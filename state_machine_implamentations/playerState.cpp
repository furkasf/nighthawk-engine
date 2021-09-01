#include "playerState.h"
#include"input.h"
#include"TextureManager.h"
#include"pauseState.h"
#include"GameOverState.h"
#include"player.h"
#include"Enemy.h"
#include<string>
#include<iostream>

const std::string playerState::s_player = "PLAYER";

std::string playerState::getStateID() const
{
	return s_player;
}

void playerState::update()
{
	if (input::instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		Game::instance()->getStateMachine()->statePush(new PauseState());
	}

	for (int i = 0; i < m_gameObject.size(); i++)
	{
		m_gameObject[i]->update();
	}

	if (cheackCollision(dynamic_cast<sdlGameObject*>(m_gameObject[0]), dynamic_cast<sdlGameObject*>(m_gameObject[1])))
	{
		
	}
}

void playerState::draw()
{
	for (int i = 0; i < m_gameObject.size(); i++)
	{
		m_gameObject[i]->draw();
	}

}

bool playerState::onEnter()
{
	StateParse parser;
	//now we abstract  load all state initiaization under one api with paring external data resourch
	parser.parseState("text.xml", "PLAYER", &m_gameObject, &m_textureIDList);
	return true;
}

bool playerState::onExit()
{
	//remove all state textures
	for (int i = 0; i < m_textureIDList.size(); i++)
	{
		TextureManager::instance()->clearTextureMap(m_textureIDList[i]);
	}
	return true;
}

bool playerState::cheackCollision(sdlGameObject* p1, sdlGameObject *p2)
{
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	leftA = p1->getPossition().get_x();
	leftB = p2->getPossition().get_x();

	rightA = p1->getPossition().get_x() + p1->getWidth();
	rightB = p2->getPossition().get_x() + p1->getWidth();

	topA = p1->getPossition().get_y();
	topB = p2->getPossition().get_y();

	bottomA = p1->getPossition().get_y() + p1->getHeight();
	bottomB = p2->getPossition().get_y() + p2->getHeight();

	//if any side of a touc b return false
	if (leftA >= rightB) return false;
	if (rightA <= leftB) return false;
	if (topA >=  bottomB) return false;
	if (bottomA <= topB) return false;

	//if object doesnt collect retun true
	return true;
}