#pragma once
#include"stateMachime.h"
#include<SDL.h>
#include<SDL_image.h>
#include<iostream>
#include<string>

class Game
{
public:

	Game();
	static Game* instance();
	void handleEvents();
	void update();
	void draw();
	int getWidth();
	int getHeight();
	bool init(const std::string& name, int screanWidth, int screanHeiht);
	bool get_running();
	SDL_Renderer* get_renderer();
	void closeGame();
	stateMachime* getStateMachine();

private:

	int m_width;
	int m_height;

	static Game* p_instance;
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
	stateMachime* m_stateMachine;
	bool running;
};

