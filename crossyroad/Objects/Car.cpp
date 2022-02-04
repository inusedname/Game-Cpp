#include "Car.h"

Car::Car(std::string name)
{
    carSprite.setTexture(*DATA->getTexture(name));
    carSize = Vector2f(carSprite.getLocalBounds().width, carSprite.getLocalBounds().height);
}
Car::~Car()
{
}
void Car::move(DIRECTION direction, float dt)
{
    if (direction == RIGHT)
        carSprite.move(Vector2f(carSpeed, 0));
    else
        carSprite.move(Vector2f(-carSpeed, 0));
}
void Car::refresh(std::string texture, LANE_PROPERTY prop)
{
    carProperty = prop;
    carSprite.setTexture(*DATA->getTexture(texture));
    carSize = Vector2f(carSprite.getLocalBounds().width, carSprite.getLocalBounds().height);
}