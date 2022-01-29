#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
using namespace sf;

class Bee
{
public:
    Sprite beeSprite;
    bool beeActive;
    float beeSpeed;

public:
    Bee(Texture &textureBee);
    void move(Time);
};