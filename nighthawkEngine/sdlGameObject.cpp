#include "sdlGameObject.h"

sdlGameObject::sdlGameObject() : gameObject()
{

}

void sdlGameObject::update()
{
	
}

void sdlGameObject::draw()
{
	TextureManager::instance()->drawFrame(m_textureId, m_position.get_x(), m_position.get_x(), m_width, m_height, m_currentFrame, m_currentRow, m_numFrame);
}

void sdlGameObject::load(const loadPrams* params) 
{
	m_position = vector2D(params->get_x(), params->get_y());
	m_velocity = vector2D(0, 0);
	m_acceleration = vector2D(0, 0);
	m_width = params->get_width();
	m_height = params->get_height();
	m_textureId = params->get_textureID();
	m_currentRow = 0;
	m_currentFrame = 0;
	m_callbackID = params->get_callBackID();
	m_animSpeed = params->get_animSpeed();
	m_numFrame = params->get_frameNumber();
}

void sdlGameObject::clean()
{
	delete this;
}

vector2D& sdlGameObject::getPossition()
{
	return m_position;
}

int sdlGameObject::getWidth()
{
	return m_width;
}
int sdlGameObject::getHeight()
{
	return m_height;
}