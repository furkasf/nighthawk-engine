#include"Game.h"

const int FPS{ 60 };
const int delay{ 1000 / FPS };

Uint32 frameStart;
Uint32 frameEnd;
 
int main(int argf, char* arvc[])
{
	Game::instance()->init("fsm", 800, 600);
	while (Game::instance()->get_running())
	{
		frameStart = SDL_GetTicks();

		Game::instance()->handleEvents();
		Game::instance()->update();
		Game::instance()->draw();

		frameEnd = SDL_GetTicks() - frameStart;

		if (frameEnd < delay)
		{
			SDL_Delay(delay - frameEnd);
		}
	}

	return 0;
}