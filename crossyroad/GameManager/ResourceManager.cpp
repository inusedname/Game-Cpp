#pragma once
#include "ResourceManager.h"
ResourceManager::ResourceManager()
{
    m_Path = "Data/";
    m_TexturePath = m_Path + "Textures/";
    m_FontPath = m_Path + "Fonts/";
    m_SoundPath = m_Path + "Audios/";
    m_allowSound = true;
    m_screenSize.x = 1280;
    m_screenSize.y = 720;
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
    ;
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
void ResourceManager::addSound(std::string name)
{
    sf::Sound *sound = new sf::Sound();
    sf::SoundBuffer *buffet = new sf::SoundBuffer();
    buffet->loadFromFile(m_SoundPath + name + ".wav");
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
    buffet->loadFromFile(m_SoundPath + name + ".wav");
    sound->setBuffer(*buffet);
    m_MapSound.insert(std::pair<std::string, sf::Sound *>(name, sound));
    return sound;
}
Vector2f ResourceManager::getScreenSize()
{
    return m_screenSize;
}
void ResourceManager::playSound(std::string name)
{
    if (m_allowSound)
        DATA->getSound(name)->play();
}

void ResourceManager::setAllowSound(bool allow)
{
    m_allowSound = allow;
}