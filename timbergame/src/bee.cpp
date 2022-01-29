#pragma once
#include "bee.h"

Bee::Bee(Texture &textureBee)
{
    beeSprite.setTexture(textureBee);
    beeActive = 0;
    beeSpeed = 0.0f;
}

void Bee::move(Time dt)
{
    if (beeActive == false)
    {
        // How fast is the bee
        srand((int)time(0));
        beeSpeed = (rand() % 200) + 200;

        // How high is the bee
        srand((int)time(0) * 10);
        float height = (rand() % 500) + 500;
        beeSprite.setPosition(2000, height);
        beeActive = true;
    }
    else //Move the bee
    {
        beeSprite.setPosition(beeSprite.getPosition().x - (beeSpeed * dt.asSeconds()), beeSprite.getPosition().y);
        if (beeSprite.getPosition().x < -100)
            beeActive = false;
    }
}