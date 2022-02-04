#pragma once
#include "../GameManager/ResourceManager.h"
#include "Car.h"
class Lane
{
private:
    Sprite laneSprite;
    std::vector<Car> cars;
    int numCars;
    DIRECTION laneDirection;
    LANE_PROPERTY laneProperty;

public:
    Lane();
    ~Lane();
    void refresh();
    void refreshSafe();
    void setLanePosition(float, float);
    Vector2f getLanePosition();
    void Draw(RenderWindow *);
};