#include "Car.h"
Car::Car()
{

}
Car::Car(std::string name)
{
    carSprite.setTexture(*DATA->getTexture(name));
    carSize = Vector2f(carSprite.getLocalBounds().width, carSprite.getLocalBounds().height);
    padding = (128 - carSize.y) / 2.0;

    carHitboxShow.setSize(Vector2f(carSize.x, carSize.y));
    carHitboxShow.setOutlineColor(Color::Red);
    carHitboxShow.setFillColor(Color::Transparent);
    carHitboxShow.setOutlineThickness(2.0);
}
Car::~Car()
{
}
Vector2f Car::getPosition()
{
    return carSprite.getPosition();
}
Vector2f Car::getCarSize()
{
    return carSize;
}
void Car::move(float &x, float y, DIRECTION direction, float dt, float carSpeed)
{
    if (direction == RIGHT)
    {
        x += carSpeed * dt;
        carSprite.setPosition(Vector2f(x,y + padding));
        if (x >= DATA->getScreenSize().x)
        {
            x = -200;
        }
    }
    else
    {
        x -= carSpeed * dt;
        carSprite.setPosition(Vector2f(x,y + padding));
        if (x + carSize.x <= 0)
        {
            x = 1280;
        }
    }
    carHitbox.left = getPosition().x;
    carHitbox.top = getPosition().y;
}
void Car::setPosition(Vector2f pos)
{
    carSprite.setPosition(pos);
}
void Car::Draw(RenderWindow *window)
{
    window->draw(carSprite);
    //carHitboxShow.setPosition(Vector2f(carHitbox.left, carHitbox.top));
    //window->draw(carHitboxShow);
}