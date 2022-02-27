#include "MusicPlayer.h"

MusicPlayer::MusicPlayer()
{
	std::string path = "Data/BGM";
	for (const auto& entry : std::filesystem::directory_iterator(path))
	{
		if (entry.path().extension() == ".ogg")
		{
			std::string tmp = entry.path().stem().string(); 
			musicAvaiable.push_back(tmp);
		}
	}
	std::cout << "MusicPlayer run properly." << "\n";
}
MusicPlayer::~MusicPlayer()
{

}

std::string MusicPlayer::getMusic(int index)
{
	return musicAvaiable[index];
}
int MusicPlayer::getSize()
{
	return musicAvaiable.size();
}