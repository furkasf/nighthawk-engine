#include "AnimatedGraphic.h"

AnimatedGraphic::AnimatedGraphic() : sdlGameObject()
{

}

void AnimatedGraphic::draw()
{
	TextureManager::instance()->drawFrame(m_textureId, m_position.get_x(), m_position.get_y(), m_width, m_height, m_currentRow, m_currentFrame);
}

void AnimatedGraphic::update()
{
	m_currentFrame = int(((SDL_GetTicks() / (1000 / m_animSpeed)) % 2));
}

void AnimatedGraphic::clean()
{
	delete this;
}

void AnimatedGraphic::load(const loadPrams* params)
{
	sdlGameObject::load(params);
	m_animSpeed = params->get_animSpeed();
}
