#pragma once
#include "ResourceManager.h"
#include <filesystem>

#define MP MusicPlayer::GetInstance()
class MusicPlayer : public CSingleton<MusicPlayer>
{
private:
	std::vector<std::string> musicAvaiable;
public:
	MusicPlayer();
	~MusicPlayer();
	int nowPlayingIndex = 1;
	int getSize();
	std::string getMusic(int index);
};