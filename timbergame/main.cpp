#include <iostream>
#include <string>
#include <cmath>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
float const PI = 3.1456;
using namespace sf;

int main()
{
    RenderWindow window(VideoMode(1920, 1080), "Timber Game");
    Clock clk;
    // Background
    Texture textureBg;
    textureBg.loadFromFile("graphics/background.png");
    Sprite background;
    background.setTexture(textureBg);
    background.setPosition(0, 0);
    // Background was drawn

    // Tree
    Texture textureTree;
    textureTree.loadFromFile("graphics/tree.png");
    Sprite tree;
    tree.setTexture(textureTree);
    tree.setPosition(810, 0);
    // Tree was drawn

    // Bee
    Texture textureBee;
    textureBee.loadFromFile("graphics/bee.png");
    Sprite bee;
    bee.setTexture(textureBee);
    bee.setPosition(0, 800);
    bool beeActive = 0;
    float beeSpeed = 0.0f;
    // Bee was drawn

    // Clouds
    Texture textureCloud;
    textureCloud.loadFromFile("graphics/cloud.png");
    Sprite cloud1, cloud2, cloud3;

    cloud1.setTexture(textureCloud);
    cloud2.setTexture(textureCloud);
    cloud3.setTexture(textureCloud);

    cloud1.setPosition(0, 0);
    cloud2.setPosition(0, 250);
    cloud3.setPosition(0, 500);

    bool cloud1Active = 0;
    bool cloud2Active = 0;
    bool cloud3Active = 0;

    float cloud1Speed = 0.0;
    float cloud2Speed = 0.0;
    float cloud3Speed = 0.0;
    //

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        Time dt = clk.restart();
        //==========================Bee Movement===========================//
        if (beeActive == false)
        {
            // How fast is the bee
            srand((int)time(0));
            beeSpeed = (rand() % 200) + 200;

            // How high is the bee
            srand((int)time(0) * 10);
            float height = (rand() % 500) + 500;
            bee.setPosition(2000, height);
            beeActive = true;
        }
        else //Move the bee
        {
            bee.setPosition(bee.getPosition().x - (beeSpeed * dt.asSeconds()), bee.getPosition().y);
            if (bee.getPosition().x < -100)
                beeActive = false;
        }
        //=========================Clouds Movement===========================//
        if (cloud1Active == false)
        {
            // How fast is the cloud
            srand((int)time(0) * 10);
            cloud1Speed = (rand() % 200);

            // How high is the cloud
            srand((int)time(0) * 10);
            float height = (rand() % 150);
            cloud1.setPosition(-200, height);
            cloud1Active = true;
        }
        else
        {
            cloud1.setPosition(cloud1.getPosition().x + (cloud1Speed * dt.asSeconds()), cloud1.getPosition().y);
            if (cloud1.getPosition().x > 1920)
                cloud1Active = false;
        }

        //Render
        window.clear();
        window.draw(background);
        window.draw(tree);
        window.draw(bee);
        window.draw(cloud1);
        window.draw(cloud2);
        window.draw(cloud3);
        window.display();
        //End render
    }
}