#pragma once
#include "hud.h"

Hud::Hud(Font &font)
{
    welcomeText.setFont(font);
    welcomeText.setString("Press Enter to start!");
    welcomeText.setCharacterSize(75);
    welcomeText.setFillColor(Color::White);

    gameOverText.setFont(font);
    gameOverText.setString("Time over\nScore = ");
    gameOverText.setCharacterSize(75);
    gameOverText.setFillColor(Color::White);

    scoreText.setFont(font);
    scoreText.setString("Score = ");
    scoreText.setCharacterSize(100);
    scoreText.setFillColor(Color::White);

    // Positioning
    FloatRect bound = welcomeText.getLocalBounds();
    welcomeText.setOrigin(bound.left + bound.width / 2.0, bound.top + bound.height / 2.0);
    welcomeText.setPosition(1920 / 2.0, 1080 / 2.0);

    bound = gameOverText.getLocalBounds();
    gameOverText.setOrigin(bound.left + bound.width / 2.0, bound.top + bound.height / 2.0);
    gameOverText.setPosition(1920 / 2.0, 1080 / 2.0);

    timeBar.setSize(Vector2f(400, 80));
    timeBar.setFillColor(Color::Red);
    timeBar.setPosition(1920 / 2 - 400 / 2, 980);

    scoreText.setPosition(20, 20);
}
void Hud::updateHUD(float drownSpeed, float timeRemaining, int score)
{
    timeBar.setSize(Vector2f(drownSpeed * timeRemaining, 80));
    scoreText.setString("Score = " + std::to_string(score));
}