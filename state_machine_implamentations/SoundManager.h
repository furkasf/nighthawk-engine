#pragma once
#include<SDL_mixer.h>
#include<map>
#include<iostream>
#include<string>

enum sound_type{MUSIC, CHUNK};

class SoundManager
{
public:

	static SoundManager* instance();

	bool load(std::string fileName, std::string id, sound_type type);

	void playSound(std::string id, int loop);
	void playMusic(std::string id, int loop);

private:

	static SoundManager* m_instance;

	//maps which hold music and sound effects
	std::map<std::string, Mix_Chunk*> m_chunk;
	std::map<std::string, Mix_Music*> m_music;

	SoundManager();
	~SoundManager();
};

