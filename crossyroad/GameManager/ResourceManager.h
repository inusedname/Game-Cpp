#pragma once
#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include "Singleton.h"
using namespace sf;

#define DATA ResourceManager::GetInstance()

enum DIRECTION
{
    LEFT,
    RIGHT,
    NONE,
};

enum LANE_PROPERTY
{
    CLEAR,
    NORMAL,
    SPECIAL,
    TRAIN,
};

class ResourceManager : public CSingleton<ResourceManager>
{
public:
    ResourceManager();
    ~ResourceManager();
    void addTexture(std::string name);
    void removeTexture(std::string name);
    sf::Texture *getTexture(std::string name);

    void addFont(std::string name);
    void removeFont(std::string name);
    sf::Font *getFont(std::string name);

    void addSound(std::string name);
    void removeSound(std::string name);
    sf::Sound *getSound(std::string name);

    void playSound(std::string name);
    void setAllowSound(bool allow);
    void setScreenSize(Vector2f);
    Vector2f getScreenSize();
    void setAllowFullscreen(bool allow);

private:
    std::map<std::string, sf::Texture *>
        m_MapTexture;
    std::map<std::string, sf::Font *>
        m_MapFont;
    std::map<std::string, sf::Sound *>
        m_MapSound;

    std::string m_Path;
    std::string m_TexturePath;
    std::string m_FontPath;
    std::string m_SoundPath;

    Vector2f m_screenSize;
    bool m_allowSound;
    bool m_allowFullscreen;
};