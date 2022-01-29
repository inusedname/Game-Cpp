#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "src/cloud.h"
#include "src/branch.h"
#include "src/hud.h"
#include "src/bee.h"
using namespace sf;

int main()
{
    // =============================== LOADING TEXTURE & FONTs ================================= //
    Texture textureBg;
    Texture textureTree;
    Texture textureBee;
    Texture textureCloud;
    Texture textureBranch;
    Font font;
    textureBg.loadFromFile("graphics/background.png");
    textureTree.loadFromFile("graphics/tree.png");
    textureBee.loadFromFile("graphics/bee.png");
    textureCloud.loadFromFile("graphics/cloud.png");
    textureBranch.loadFromFile("graphics/branch.png");
    font.loadFromFile("fonts/KOMIKAP_.ttf");

    // BASIC SETUP ====================================================================== //
    RenderWindow window(VideoMode(1920, 1080), "Timber Game");
    window.setFramerateLimit(60);
    Clock clk;
    int idle = 1;
    int score = 0;
    // ================================================================================== //
    Sprite background;
    background.setTexture(textureBg);
    background.setPosition(0, 0);
    Sprite tree;
    tree.setTexture(textureTree);
    tree.setPosition(810, 0);
    Bee bee(textureBee);
    Clouds clouds(textureCloud, 1);
    Branches branches(textureBranch, 6);
    Hud HUD(font);
    //=============================Time Remain============================

    Time gameTimeTotal;
    float timeRemaining = 6.0f;
    float drownSpeed = 400 / timeRemaining;

    //===========================================GAMELOOP==================================//
    while (window.isOpen())
    {
        Time dt = clk.restart();
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        if (Keyboard::isKeyPressed(Keyboard::Escape))
            idle = 1;
        if (Keyboard::isKeyPressed(Keyboard::Enter))
        {
            idle = 0;
            if (timeRemaining <= 0.0f)
            {
                score = 0;
                timeRemaining = 6.0f;
            }
        }
        if (idle == 1)
        {
            window.clear(Color::Black);
            window.draw(HUD.welcomeText);
            window.display();
            continue;
        }
        else if (idle == -1)
        {
            window.clear(Color::Black);
            HUD.gameOverText.setString("Time over\nScore = " + std::to_string(score));
            window.draw(HUD.gameOverText);
            window.display();
            continue;
        }
        bee.move(dt);
        clouds.moveClouds(dt);
        HUD.updateHUD(drownSpeed, timeRemaining, score);
        // ==========================================Time Update==============================//
        timeRemaining -= dt.asSeconds();
        if (timeRemaining <= 0.0f)
        {
            idle = -1;
            continue;
        }
        // ============================================Render=================================//
        window.clear();
        window.draw(background);
        for (int i = 0; i < clouds.clouds.size(); i++)
            window.draw(clouds.clouds[i].spriteCloud);
        for (int i = 0; i < branches.branches.size(); i++)
            window.draw(branches.branches[i].spriteBranch);
        window.draw(tree);
        window.draw(bee.beeSprite);
        window.draw(HUD.scoreText);
        window.draw(HUD.timeBar);
        window.display();
    }
}