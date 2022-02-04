#pragma once
#include "../GameManager/ResourceManager.h"

class Car
{
private:
    Sprite carSprite;
    Vector2f carSize;
    float carSpeed;
    LANE_PROPERTY carProperty;

public:
    Car(std::string);
    ~Car();
    void refresh(std::string texture, LANE_PROPERTY);
    void move(DIRECTION, float dt);
};