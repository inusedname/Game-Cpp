#include "Lane.h"

Lane::Lane()
{
    numCars = 5;
    Lane::refresh();
}
Lane::~Lane()
{
}
void Lane::refresh()
{
    int x = rand() % 64;
    if (x % 5 == 0)
    {
        laneProperty = SPECIAL;
        laneSprite.setTexture(*DATA->getTexture("roadlane"));
    }
    else if (x % 8 == 0)
    {
        laneProperty = NORMAL;
        laneSprite.setTexture(*DATA->getTexture("roadlane"));
    }
    else if (x % 4 == 0)
    {
        laneProperty = WATER;
        laneSprite.setTexture(*DATA->getTexture("waterlane"));
    }
    else
    {
        laneProperty = EMPTY;
        laneSprite.setTexture(*DATA->getTexture("lane" + (x % 3)));
    }
    if (laneProperty == NORMAL)
    {
        for (int i = 1; i <= numCars; i++)
        {
            int x = (rand() * i) % 10 + 1;
            cars[i].refresh("car" + x, laneProperty);
        }
    }
    else if (laneProperty == SPECIAL)
    {
        for (int i = 1; i <= numCars; i++)
        {
            int x = (rand() * i) % 4 + 1;
            cars[i].refresh("specialcar" + x, laneProperty);
        }
    }
}
void Lane::refreshSafe()
{
    int x = rand() % 64;
    laneProperty = EMPTY;
    laneSprite.setTexture(*DATA->getTexture("lane" + (x % 3)));
}
void Lane::setLanePosition(float x, float y)
{
    laneSprite.setPosition(x, y);
}
Vector2f Lane::getLanePosition()
{
    return laneSprite.getPosition();
}
void Lane::Draw(RenderWindow *window)
{
    window->draw(laneSprite);
    
}