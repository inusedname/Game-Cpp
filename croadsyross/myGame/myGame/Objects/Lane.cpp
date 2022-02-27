#include "Lane.h"

Lane::Lane()
{
    timeCounter = 0;
    timeToNextSpawn = 0;
    numCars = 7;
    numLeafs = 4;
    leafs.resize(numLeafs);
    tilePos.resize(10);
}
Lane::~Lane()
{
}
void Lane::refresh()
{
    timeCounter = 0;
    timeToNextSpawn = 0;
    while (carsProperty.size())
        carsProperty.pop_back();
    int x = rand();
    if (x % 5 == 0)
    {
        laneProperty = SPECIAL;
        if (x % 2)
            laneDirection = DIRECTION::RIGHT;
        else
            laneDirection = DIRECTION::LEFT;
        carSpeed = 450 + (rand() * 15) % 75;
        laneSprite.setTexture(*DATA->getTexture("roadlane"));
    }
    else if (x % 4 == 0)
    {
        laneProperty = NORMAL;
        if (x % 2)
            laneDirection = DIRECTION::LEFT;
        else 
            laneDirection = DIRECTION::RIGHT;
        carSpeed = 350 + (rand() * 15) % 75;
        laneSprite.setTexture(*DATA->getTexture("roadlane"));
    }
    else if (x % 7 == 0)
    {
        laneProperty = WATER;
        laneSprite.setTexture(*DATA->getTexture("waterlane"));
        for (int i = 0; i < numLeafs; i++)
        {
            int x = (rand() % 7) + 1;
            leafs[i] = x;
        }
    }
    else
    {
        laneProperty = EMPTY;
        for (int i = 0; i < 10; i++)
        {
            x = rand() % 2;
            tilePos[i] = x;
        }
    }
}
void Lane::refreshSafe()
{
    laneProperty = EMPTY;
    for (int i = 0; i < 10; i++)
    {
        int x = rand() % 2;
        tilePos[i] = x;
    }
}
void Lane::setLanePosition(Vector2f pos)
{
    laneSprite.setPosition(pos);
}
void Lane::genCar()
{
    int div = 0;
    if (laneProperty == NORMAL)
    {
        div = 10;
    }
    else if (laneProperty == SPECIAL)
    {
        div = 4;
    }
    if (div != 0)
    {
        int x = (rand() * (5 + carsProperty.size())) % div;
        if (laneDirection == LEFT)
            carsProperty.push_back(std::pair<int, float>(x, 1280));
        else
            carsProperty.push_back(std::pair<int, float>(x, -200));
        
    }
}
bool Lane::carsAndPlayerCollision(Player player)
{
    bool laneProp = (laneProperty == SPECIAL);
    bool result = false;
    for (int i = 0; result == false && i < carsProperty.size(); i++)
    {
        Vector2f carSize = POOL->getCar(carsProperty[i].first, laneProp, laneDirection == LEFT)->getCarSize();
        FloatRect tmp(Vector2f(carsProperty[i].second, getLanePosition().y), carSize);
        result = collisionChecker.simpleCollisionCheck(player.getPlayerHitbox(), tmp);
    }
    return result;
}
bool Lane::waterAndPlayerCollision(Player player)
{
    bool result = true;
    for (int i = 0; result == true && i < leafs.size(); i++)
    {
        Vector2f leafSize = POOL->getLeaf()->getLeafSize();
        FloatRect tmp(Vector2f(leafs[i] * 128, getLanePosition().y), leafSize);
        result = !collisionChecker.simpleCollisionCheck(player.getPlayerHitbox(), tmp);
    }
    return result;
}
Vector2f Lane::getLanePosition()
{
    return laneSprite.getPosition();
}
LANE_PROPERTY Lane::getLaneProperty()
{
    return laneProperty;
}
void Lane::DrawLane(RenderWindow* window)
{
    if (laneProperty != EMPTY)
    {
        window->draw(laneSprite);
        return;
    }
    int y = laneSprite.getPosition().y;
    int x;
    for (int i = 0; i < 10; i++)
    {
        POOL->setPosTile(Vector2f(128 * i, y), tilePos[i]);
        POOL->DrawTile(window, tilePos[i]);
    }
}    
void Lane::DrawCars(RenderWindow* window, float dt, int i)
{
    if (laneProperty == NORMAL || laneProperty == SPECIAL)
    {
        bool laneProp = (laneProperty == SPECIAL);
        bool areCarsToTheLeft = (laneDirection == LEFT);
        if (carsProperty.size() < numCars)
        {
            if (timeCounter >= (double)timeToNextSpawn)
            {
                genCar();
                timeToNextSpawn = log(((100 + (3 * i * i)) * i) % 3 + 3);
                timeCounter = 0;
            }
            else
                timeCounter += dt;
        }
        for (int i = 0; i < carsProperty.size(); i++)
        {
            POOL->getCar(carsProperty[i].first, laneProp, areCarsToTheLeft)->move(carsProperty[i].second, getLanePosition().y, laneDirection, dt, carSpeed);
            if (carsProperty[i].second > -200 && carsProperty[i].second < 1280)
                POOL->getCar(carsProperty[i].first, laneProp, areCarsToTheLeft)->Draw(window);
            else
                carsProperty.pop_front(), i--;
        }
    }
}

void Lane::DrawLeaf(RenderWindow* window)
{
    if (laneProperty == WATER)
    {
        for (int i = 0; i < numLeafs; i++)
        {
            Vector2f pos;
            pos.y = getLanePosition().y + 64;
            pos.x = (leafs[i] * 128) + 64;
            POOL->getLeaf()->setLeafPosition(pos);
            POOL->getLeaf()->Draw(window);
        }
    }
}
