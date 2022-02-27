#pragma once
#include "../GameManager/ResourceManager.h"

class Car
{
private:
    Sprite carSprite;
    Vector2f carSize;
    Rect<float> carHitbox;
    float padding;
    RectangleShape carHitboxShow;

public:
    Car();
    Car(std::string);
    ~Car();
    void setPosition(Vector2f);
    Vector2f getPosition();
    Vector2f getCarSize();
    void move(float &x, float y, DIRECTION, float dt, float carSpeed);
    void Draw(RenderWindow *);
};