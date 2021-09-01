#pragma once
#include"Game.h"
#include<map>

class TextureManager
{
public:

	static TextureManager* instance();
	bool load(std::string path, SDL_Renderer* renderer, std::string textureID);
	void draw(std::string id, int x, int y, int desx, int desy , int width, int height);
	void draw(std::string id, int x, int y , int width, int height);
	void drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, double angle = 0, Uint8 alpha = 255, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void clearTextureMap(std::string id);
private:
	std::map<std::string, SDL_Texture*> m_textureID;
	static TextureManager* p_instance;
};

