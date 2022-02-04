#pragma once
#include "../GameManager/ResourceManager.h"
#include "Lane.h"

class Map : public CSingleton<Map>
{
private:
    std::deque<Lane> lanes;
    int NUM_LANES;

public:
    Map();
    void refresh();
    void Draw(RenderWindow *);
};