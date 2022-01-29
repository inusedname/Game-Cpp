#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
using namespace sf;

class Hud
{
public:
    Text welcomeText;
    Text gameOverText;
    Text scoreText;
    RectangleShape timeBar;

public:
    Hud(Font &);
    void updateHUD(float drownSpeed, float timeRemaining, int score);
};