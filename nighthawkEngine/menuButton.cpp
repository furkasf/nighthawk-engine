#include "menuButton.h"
#include"input.h"

menuButton::menuButton() : sdlGameObject()
{

}

void menuButton::draw()

{
	TextureManager::instance()->draw(m_textureId, m_position.get_x(), m_position.get_y(), m_width, m_height, Game::instance()->get_renderer(), SDL_FLIP_NONE);
}

void menuButton::update()
{
	//get mouse position from inputhandle class instace in order to use in collision
	vector2D* p_mousePos = input::instance()->get_mouseLocation();
	//std::cout  << "mouse location \n" << "x:  " << p_mousePos->get_x() << "\ny:  " << p_mousePos->get_y() << "\n";
	//std::cout << "exit location  \n" << "x:  " << m_Dposition.get_x() << "\ny:  " << m_Dposition.get_y() << "\n";
	//cheack basic box collision dedection to dedect mouse touch the button menu or not
	if (p_mousePos->get_x() < (m_position.get_x() + m_width) && p_mousePos->get_x() > m_position.get_x()
		&& p_mousePos->get_y() < (m_position.get_y() + m_height) && p_mousePos->get_y() > m_position.get_y())
	{
		if (input::instance()->get_mouseButtonState(LEFT) && m_bReleased)
		{

			m_currentFrame = CLICKED;
			m_callback();
			m_bReleased = false;
			std::cout << "menu clicked\n";

		}
		else if (!input::instance()->get_mouseButtonState(LEFT))
		{
			m_currentFrame = MOUSE_OVER;
			m_bReleased = true;
			std::cout << "mouse over on menu \n"; 
		}
		else
		{
			m_currentFrame = MOUSE_OUT;
			std::cout << "mouse out of menu \n";
		}
	}
}

void menuButton::clean()
{
	//use the base class clean function
	delete this;
}

void menuButton::load(const loadPrams* params)
{
	//start at 0
	sdlGameObject::load(params);
	m_callbackID = params->get_callBackID();
	m_currentFrame = MOUSE_OUT;
}

void menuButton::setCallback(void (*callback)())
{
	m_callback = callback;
}

int menuButton::getCallBackID()
{
	return m_callbackID;
}