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

void TextureManager::draw(std::string id, int x, int y, int width, int height,
	SDL_Renderer* pRenderer, SDL_RendererFlip flip)
{
	SDL_Rect srcRect;
	SDL_Rect destRect;

	destRect.w = width;
	destRect.h = height;
	destRect.x = x;
	destRect.y = y;

	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = destRect.w;
	srcRect.h = destRect.h;

	SDL_RenderCopyEx(pRenderer, m_textureID[id], &srcRect, &destRect, 0, 0, flip);
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

void TextureManager::drawTile(std::string id, int margin, int spacing, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRenderer)
{
	SDL_Rect srcRect;
	SDL_Rect desRect;
	//grab places of tile from tile map
	srcRect.x = margin + (spacing + width) * currentFrame;
	srcRect.y = margin + (spacing + width) * currentRow;
	srcRect.w = desRect.w = width;
	srcRect.h = desRect.h = height;

	//tiles location on screen
	desRect.x = x;
	desRect.y = y;

	SDL_RenderCopyEx(pRenderer, m_textureID[id], &srcRect, &desRect, 0, 0, SDL_FLIP_NONE);
}

void TextureManager::clearTextureMap(std::string id)
{
	m_textureID.erase(id);
}