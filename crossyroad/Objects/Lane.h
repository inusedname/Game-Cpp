#pragma once
#include "../GameManager/ResourceManager.h"
#include "Car.h"
class Lane
{
private:
    std::vector<Car> cars;
    DIRECTION laneDirection;
public:
    Lane();
    ~Lane();
    
};