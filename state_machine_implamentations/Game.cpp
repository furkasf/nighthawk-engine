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

Game::Game() : m_window{ nullptr } , m_renderer{ nullptr }, running{ false } , m_stateMachine{ new stateMachime() }, m_width{0}, m_height{0}
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
	m_width = screanWidth;
	m_height = screanHeiht;

	m_window = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_width, m_height, SDL_WINDOW_SHOWN);
	if (m_window != nullptr)
	{
		m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
		if (m_renderer != nullptr)
		{
			running = true;
		}
		//register game objects factors befor object creation
		GameObjectFactory::instance()->RegisterFactory("Player", new playerCreator());
		GameObjectFactory::instance()->RegisterFactory("Enemy", new enemyCreator());
		GameObjectFactory::instance()->RegisterFactory("MenuButton", new menuCreator());
		GameObjectFactory::instance()->RegisterFactory("AnimatedGraphic", new animatedGraphicCreator());

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

int Game::getWidth()
{
	return m_width;
}

int Game::getHeight()
{
	return m_height;
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