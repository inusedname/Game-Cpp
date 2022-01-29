#pragma once
#include "../GameManager/ResourceManager.h"

class Car
{
private:
    Sprite carSprite;
    float carSpeed;

public:
    Car();
    ~Car();
    void move(DIRECTION);
};