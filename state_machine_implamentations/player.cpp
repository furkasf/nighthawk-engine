#include "player.h"
#include"PauseState.h"

player::player() : sdlGameObject()
{

}

void player::draw()
{
	if (m_velocity.get_x() > 0)
	{
		TextureManager::instance()->drawFrame(m_textureId, (Uint32)m_position.get_x(), (Uint32)m_position.get_y(), m_width
			, m_height, m_currentFrame, SDL_FLIP_HORIZONTAL);
	}
	else
	{
		TextureManager::instance()->drawFrame(m_textureId, (Uint32)m_position.get_x(), (Uint32)m_position.get_y(), m_width
			, m_height, m_currentFrame, m_currentRow);
	}
}

void player::update()
{
	
	//for helocopter/player follow the curser
	vector2D* target = input::instance()->get_mouseLocation();
	m_velocity = *target - m_position;
	//for the slow down the velocity of player
	m_velocity /= 50;
	m_position += m_velocity;
	if (input::instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		Game::instance()->getStateMachine()->statePush(new PauseState());
	}
}

void player::load(const loadPrams* params)
{
	sdlGameObject::load(params);
}

void player::clean()
{
	delete this;
}