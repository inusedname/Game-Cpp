#pragma once
#include "cloud.h"

void Cloud::move(Time dt, int seed)
{
    if (cloudActive == false)
    {
        // How fast is the cloud
        srand((int)time(0) * (seed * 37));
        cloudSpeed = (rand() % 200 + 100);

        // How high is the cloud
        srand((int)time(0) * seed * 12);
        float height = (rand() % (100 + seed * 50));
        spriteCloud.setPosition(-200, height);
        cloudActive = true;
    }
    else
    {
        spriteCloud.setPosition(spriteCloud.getPosition().x + (cloudSpeed * dt.asSeconds()), spriteCloud.getPosition().y);
        if (spriteCloud.getPosition().x > 1920)
            cloudActive = false;
    }
}
Clouds::Clouds(Texture &cloudTexture, int quantity)
{
    clouds.resize(quantity);
    for (int i = 0; i < clouds.size(); i++)
    {
        clouds[i].spriteCloud.setTexture(cloudTexture);
        clouds[i].cloudActive = false;
        clouds[i].cloudSpeed = 0.0f;
    }
}
void Clouds::moveClouds(Time dt)
{
    for (int i = 0; i < clouds.size(); i++)
        clouds[i].move(dt, i);
}
