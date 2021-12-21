#include"input.h"

input* input::p_instance = 0;


input::input() : m_mousePosition{ new vector2D(0 ,0) }, m_keystate{ SDL_GetKeyboardState(0) }
{

	for (int i = 0; i < MOUSE_BUTTON_MAX; i++)
	{
		//default setting of mouse button after initialize instace
		m_mouseButtonState.push_back(false);
	}

}

void input::update()
{
	SDL_Event e;

	while (SDL_PollEvent(&e))
	{
		switch (e.type)
		{
		case SDL_QUIT:Game::instance()->closeGame(); break;
		case SDL_MOUSEBUTTONDOWN: mouseButtonDown(e); break;
		case SDL_MOUSEBUTTONUP: mouseButtonUp(e); break;
		case SDL_MOUSEMOTION: mouseMotion(e); break;
		case SDL_KEYDOWN:onKeyDown(); break;
		case SDL_KEYUP:onKeyUp(); break;
		}


	}
}

bool input::isKeyDown(SDL_Scancode key)
{
	//if key is pressed -- we set default skeystate to non pressed
	if (m_keystate != 0)
	{
		//cheak if SDl_getstatae return 1, if funtion return one this mean key is presed
		if (m_keystate[key] == 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	return false;
}

bool input::get_mouseButtonState(int state)
{
	return m_mouseButtonState[state];
}

void input::clean()
{
	delete m_mousePosition;
}

void input::mouseButtonDown(SDL_Event& e)
{


	if (e.button.button == SDL_BUTTON_LEFT)
	{
		m_mouseButtonState[LEFT] = true;
	}
	if (e.button.button == SDL_BUTTON_MIDDLE)
	{
		m_mouseButtonState[MIDDLE] = true;
	}
	if (e.button.button == SDL_BUTTON_RIGHT)
	{
		m_mouseButtonState[RIGHT] = true;
	}

}

void input::mouseButtonUp(SDL_Event& e)
{
	if (e.button.button == SDL_BUTTON_LEFT)
	{
		m_mouseButtonState[LEFT] = false;
	}
	if (e.button.button == SDL_BUTTON_MIDDLE)
	{
		m_mouseButtonState[MIDDLE] = false;
	}
	if (e.button.button == SDL_BUTTON_RIGHT)
	{
		m_mouseButtonState[RIGHT] = false;
	}

}

void input::onKeyDown()
{
	m_keystate = SDL_GetKeyboardState(0);
}

void input::onKeyUp()
{
	m_keystate = SDL_GetKeyboardState(0);
}


void input::mouseMotion(SDL_Event& e)
{
	m_mousePosition->set_x(e.motion.x);
	m_mousePosition->set_y(e.motion.y);
}