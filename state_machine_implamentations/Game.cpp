#include "Game.h"
#include"menuState.h"
#include"mainMenuState.h"
#include"menuCreator.h"
#include"animatedGraphicCreator.h"
#include"playerCreator.h"
#include"enemyCreator.h"
#include"GameObjectFactory.h"
#include"input.h"

//initialize static instance of class
Game* Game::p_instance = nullptr;

Game::Game() : m_window{ nullptr } , m_renderer{ nullptr }, running{ false } , m_stateMachine{ new stateMachime() }
{
}

Game* Game::instance()
{
	if (p_instance == nullptr)
	{
		p_instance = new Game();
		return p_instance;
	}

	return p_instance;
}

bool Game::init(const std::string& name, int screanWidth, int screanHeiht)
{
	m_window = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screanWidth, screanHeiht, SDL_WINDOW_SHOWN);
	if (m_window != nullptr)
	{
		m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
		if (m_renderer != nullptr)
		{
			running = true;
		}
		//register game objects factors befor object creation
		GameObjectFactory::instance()->RegisterFactory("PLAYER", new playerCreator());
		GameObjectFactory::instance()->RegisterFactory("ENEMY", new enemyCreator());
		GameObjectFactory::instance()->RegisterFactory("MENUBUTTON", new menuCreator());
		GameObjectFactory::instance()->RegisterFactory("ANIMATEDGRPHIC", new animatedGraphicCreator());

 		m_stateMachine->statePush(new mainMenuState());

	}
	return running;
}

void Game::handleEvents()
{
	input::instance()->update();
}

void Game::update()
{
	m_stateMachine->update();
}

void Game::draw()
{
	SDL_RenderClear(m_renderer);

	m_stateMachine->draw();

	SDL_RenderPresent(m_renderer);
}

bool Game::get_running()
{
	return running;
}

SDL_Renderer* Game::get_renderer()
{
	return m_renderer;
}

void Game::closeGame()
{
	running = false;
}

stateMachime* Game::getStateMachine()
{
	return m_stateMachine;
}