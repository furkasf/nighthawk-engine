#include "TextureManager.h"

TextureManager* TextureManager::p_instance = nullptr;

TextureManager* TextureManager::instance()
{
	if (p_instance == nullptr)
	{
		p_instance = new TextureManager();
		return p_instance;
	}

	return p_instance;
}

bool TextureManager::load(std::string path, SDL_Renderer* renderer, std::string textureID)
{
	SDL_Surface* surface = IMG_Load(path.c_str());
	if (surface == nullptr)
	{
		std::cout << "error :" << IMG_GetError();
		std::cout << "surface doesn't loaded\n";
		return false;
	}
	
	m_textureID[textureID] = SDL_CreateTextureFromSurface(Game::instance()->get_renderer(), surface);
	
	if (m_textureID[textureID] == nullptr)
	{
		std::cout << "texture doesnt added to table \n";
	}

	SDL_FreeSurface(surface);
	surface = nullptr;


	return true;
}

void TextureManager::draw(std::string id, int x, int y, int desx, int desy, int width, int height)
{
	//SDL_SetRenderDrawColor(Game::instance()->get_renderer(), 255, 255, 255, 255);
	SDL_Rect src;
	SDL_Rect dst;

	src.x = x;
	dst.x = desx;
	src.y = y;
	dst.y = desy;
	src.w = width;
	src.h = height;
	dst.w = width;
	dst.h = height;

	
	if (SDL_RenderCopy(Game::instance()->get_renderer(), m_textureID[id], &src, &dst) != 0)
	{
		std::cout << "error : " << SDL_GetError() << "\n";
		std::cout << "texture can't drawed \n";
	}
}

void TextureManager::draw(std::string id, int x, int y, int width, int height)
{
	//SDL_SetRenderDrawColor(Game::instance()->get_renderer(), 255, 255, 255, 255);
	SDL_Rect src;
	SDL_Rect dst;

	src.x = x;
	dst.x = x;
	src.y = y;
	dst.y = y;
	src.w = width;
	src.h = height;
	dst.w = width;
	dst.h = height;


	if (SDL_RenderCopy(Game::instance()->get_renderer(), m_textureID[id], &src, &dst) != 0)
	{
		std::cout << "error : " << SDL_GetError() << "\n";
		std::cout << "texture can't drawed \n";
	}
}

void TextureManager::drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, double angle, Uint8 alpha  , SDL_RendererFlip flip)
{
	SDL_Rect srcRect;
	SDL_Rect destRect;

	destRect.x = x;
	destRect.y = y;
	destRect.w = width;
	destRect.h = height;

	srcRect.x = width * currentFrame ;
	srcRect.y = height * currentRow ;
	srcRect.w = destRect.w;
	srcRect.h = destRect.h;

	//std::cout << "id:" << id << std::endl;
	//set the alpha of the texture and pass in the angle
	SDL_SetTextureAlphaMod(m_textureID[id], alpha);
	if (SDL_RenderCopyEx(Game::instance()->get_renderer(), m_textureID[id], &srcRect, &destRect, angle, 0, flip) != 0)
	{
		std::cout << "error : " << SDL_GetError() << "\n";
		std::cout << "texture can't drawed \n";
	}
}

void TextureManager::clearTextureMap(std::string id)
{
	m_textureID.erase(id);
}