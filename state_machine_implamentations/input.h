#pragma once
#include "input.h"
#include"vector2D.h"
#include"Game.h"
#include<vector>
#include<SDL.h>

enum mause_buttons { LEFT, MIDDLE, RIGHT, MOUSE_BUTTON_MAX };


class input
{
public:

	static input* instance()
	{
		if (p_instance == 0)
		{
			return p_instance = new input();
		}
		return p_instance;
	}

	void update();

	bool get_mouseButtonState(int state);
	bool isKeyDown(SDL_Scancode key);

	vector2D* get_mouseLocation() { return m_mousePosition; }

	void clean();

private:

	input();
	std::vector<bool> m_mouseButtonState;
	vector2D* m_mousePosition;
	static input* p_instance;
	const Uint8* m_keystate;

	//keyvoar events
	void onKeyDown();
	void onKeyUp();

	//mouse events
	void mouseButtonDown(SDL_Event& e);
	void mouseButtonUp(SDL_Event& e);

	

	void mouseMotion(SDL_Event& e);
};
