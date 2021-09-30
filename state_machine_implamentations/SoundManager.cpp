#include "SoundManager.h"

SoundManager* SoundManager::m_instance = nullptr;

SoundManager::SoundManager()
{
	Mix_OpenAudio(22050, AUDIO_S16, 2, 4096);
}

SoundManager::~SoundManager()
{
	Mix_CloseAudio();
}

SoundManager* SoundManager::instance()
{
	if (m_instance == nullptr)
	{
		m_instance = new SoundManager();
		return m_instance;
	}
	
	return m_instance;
}

bool SoundManager::load(std::string fileName, std::string id, sound_type type)
{
	if (type == MUSIC)
	{
		Mix_Music* pMusic = Mix_LoadMUS(fileName.c_str());
		if (pMusic == nullptr)
		{
			//if music file is emty
			std::cout << Mix_GetError() << "\n";
			return false;
		}
		//add music in music map
		m_music[id] = pMusic;
		return true;
	}

	if (type == CHUNK)
	{
		Mix_Chunk* pChunk = Mix_LoadWAV(fileName.c_str());
		if (pChunk == nullptr)
		{
			std::cout << Mix_GetError() << "\n";
			return false;
		}
		m_chunk[id] = pChunk;
		return true;
	}

	return false;
}

void SoundManager::playSound(std::string id, int loop)
{
	Mix_PlayMusic(m_music[id], loop);
}
void SoundManager::playMusic(std::string id, int loop)
{
	Mix_PlayChannel(-1, m_chunk[id], loop);
}