#include "ResourceManager.h"
#include <fstream>
ResourceManager::ResourceManager()
{
    changeFrameLimit = false;
    stopTheGame = false;
    m_Path = "Data/";
    m_TexturePath = m_Path + "Textures/";
    m_FontPath = m_Path + "Fonts/";
    m_SoundPath = m_Path + "SFX/";
    m_MusicPath = m_Path + "BGM/";
    m_allowSound = true;
    m_screenSize.x = 1280; // do not change this
    m_screenSize.y = 768; // do not change this
    loadInit();
}

ResourceManager::~ResourceManager()
{
    for (auto it : m_MapTexture)
    {
        if (it.second != nullptr)
        {
            delete it.second;
        }
    }
    m_MapTexture.clear();

    for (auto it : m_MapFont)
    {
        if (it.second != nullptr)
        {
            delete it.second;
        }
    }
    m_MapFont.clear();
}

void ResourceManager::addTexture(std::string name)
{
    sf::Texture *texture = new sf::Texture();
    texture->loadFromFile(m_TexturePath + name + ".png");

    auto it = m_MapTexture.find(name);
    if (it != m_MapTexture.end())
    {
        return;
    }
    m_MapTexture.insert(std::pair<std::string, sf::Texture *>(name, texture));
}

void ResourceManager::removeTexture(std::string name)
{
    auto it = m_MapTexture.find(name);
    if (it == m_MapTexture.end())
    {
        return;
    }
    if (it->second != nullptr)
        delete it->second;
    m_MapTexture.erase(it);
}

sf::Texture *ResourceManager::getTexture(std::string name)
{
    auto it = m_MapTexture.find(name);
    if (it != m_MapTexture.end())
    {
        return it->second;
    }
    sf::Texture *texture = new sf::Texture();
    texture->loadFromFile(m_TexturePath + name + ".png");
    m_MapTexture.insert(std::pair<std::string, sf::Texture *>(name, texture));
    return texture;
}

void ResourceManager::addFont(std::string name)
{
    sf::Font *font = new sf::Font();
    font->loadFromFile(m_TexturePath + name + ".TTF");

    auto it = m_MapFont.find(name);
    if (it != m_MapFont.end())
    {
        return;
    }
    m_MapFont.insert(std::pair<std::string, sf::Font *>(name, font));
}

void ResourceManager::removeFont(std::string name)
{
    auto it = m_MapFont.find(name);
    if (it == m_MapFont.end())
    {
        return;
    }
    if (it->second != nullptr)
        delete it->second;
    m_MapFont.erase(it);
}

sf::Font *ResourceManager::getFont(std::string name)
{
    auto it = m_MapFont.find(name);
    if (it != m_MapFont.end())
    {
        return it->second;
    }
    sf::Font *font = new sf::Font();
    font->loadFromFile(m_FontPath + name + ".TTF");
    m_MapFont.insert(std::pair<std::string, sf::Font *>(name, font));
    return font;
}

void ResourceManager::setScreenSize(Vector2f vt)
{
    m_screenSize = vt;
}
void ResourceManager::setAllowFullscreen(bool allow)
{
    m_allowFullscreen = allow;
}

int ResourceManager::getMusicSize()
{
    return m_MapMusic.size();
}

void ResourceManager::saveInit()
{
    std::ofstream file("save.txt");
    file << "highestScore " << highestScore << "\n";
    file << "frameLimit " << frameLimit << "\n";
    file << "musicVolume " << musicVolume << "\n";
    file << "sfxVolume " << sfxVolume << "\n";
    file.close();
}

void ResourceManager::loadInit()
{
    std::ifstream file("save.txt");
    std::string tmp, tmp2;
    while (file >> tmp)
    {
        file >> tmp2;
        if (tmp == "highestScore")
            highestScore = stoi(tmp2);
        else if (tmp == "frameLimit")
            frameLimit = stoi(tmp2);
        else if (tmp == "musicVolume")
            musicVolume = stoi(tmp2);
        else if (tmp == "sfxVolume")
            sfxVolume = stoi(tmp2);
    }
    file.close();
}

void ResourceManager::addSound(std::string name)
{
    sf::Sound *sound = new sf::Sound();
    sf::SoundBuffer *buffet = new sf::SoundBuffer();
    buffet->loadFromFile(m_SoundPath + name + ".ogg");
    sound->setBuffer(*buffet);
    auto it = m_MapSound.find(name);
    if (it != m_MapSound.end())
    {
        return;
    }
    m_MapSound.insert(std::pair<std::string, sf::Sound *>(name, sound));
}

void ResourceManager::removeSound(std::string name)
{
    auto it = m_MapSound.find(name);
    if (it == m_MapSound.end())
    {
        return;
    }
    if (it->second != nullptr)
        delete it->second;
    m_MapSound.erase(it);
}

sf::Sound *ResourceManager::getSound(std::string name)
{
    auto it = m_MapSound.find(name);
    if (it != m_MapSound.end())
    {
        return it->second;
    }
    sf::Sound *sound = new sf::Sound();
    sf::SoundBuffer *buffet = new sf::SoundBuffer();
    buffet->loadFromFile(m_SoundPath + name + ".ogg");
    sound->setBuffer(*buffet);
    m_MapSound.insert(std::pair<std::string, sf::Sound *>(name, sound));
    return sound;
}
void ResourceManager::addMusic(std::string name)
{
    sf::Music *music = new sf::Music();
    music->openFromFile(m_MusicPath + name + ".ogg");

    auto it = m_MapFont.find(name);
    if (it != m_MapFont.end())
    {
        return;
    }
    m_MapMusic.insert(std::pair<std::string, sf::Music *>(name, music));
}

void ResourceManager::removeMusic(std::string name)
{
    auto it = m_MapMusic.find(name);
    if (it == m_MapMusic.end())
    {
        return;
    }
    if (it->second != nullptr)
        delete it->second;
    m_MapMusic.erase(it);
}

sf::Music *ResourceManager::getMusic(std::string name)
{
    auto it = m_MapMusic.find(name);
    if (it != m_MapMusic.end())
    {
        return it->second;
    }
    sf::Music *music = new sf::Music();
    music->openFromFile(m_MusicPath + name + ".ogg");
    m_MapMusic.insert(std::pair<std::string, sf::Music *>(name, music));
    return music;
}
Vector2f ResourceManager::getScreenSize()
{
    return m_screenSize;
}
void ResourceManager::playSound(std::string name)
{
    DATA->getSound(name)->play();
    soundNowPlaying = name;
    updateVolSound();
}
void ResourceManager::playMusic(std::string name)
{
    DATA->getMusic(name)->play();
    musicNowPlaying = name;
    updateVolMusic();
}
void ResourceManager::stopMusic(std::string name)
{
    DATA->getMusic(name)->stop();
}
void ResourceManager::updateVolSound()
{
    DATA->getSound(soundNowPlaying)->setVolume(sfxVolume);
}
void ResourceManager::updateVolMusic()
{
    DATA->getMusic(musicNowPlaying)->setVolume(musicVolume);
}