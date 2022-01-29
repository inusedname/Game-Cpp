#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
using namespace sf;

class Cloud
{
public:
    Sprite spriteCloud;
    bool cloudActive;
    float cloudSpeed;

public:
    void move(Time dt, int seed);
};

class Clouds
{
public:
    std::vector<Cloud> clouds;

public:
    Clouds(Texture &cloudTexture, int quantity);
    void moveClouds(Time dt);
};
