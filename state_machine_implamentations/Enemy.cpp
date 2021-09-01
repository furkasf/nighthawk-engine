#include "Enemy.h"

Enemy::Enemy() : sdlGameObject()
{

}

void Enemy::draw()
{
	TextureManager::instance()->drawFrame(m_textureId, (int)m_position.get_x(), (int)m_position.get_y(), m_width, m_height, m_currentRow, m_currentFrame);
}

void Enemy::update()
{
	m_currentFrame = int(((SDL_GetTicks() / 100) % 2));

	if (m_position.get_y() <= 0)
	{
		m_velocity.set_y(2);

	}
	if (m_position.get_y() + m_width >= 600)
	{
		m_velocity.set_y(-2);
	}
}

void Enemy::load(const loadPrams* params)
{
	sdlGameObject::load(params);
	m_velocity.set_y(2);
}

void Enemy::clean()
{

}
