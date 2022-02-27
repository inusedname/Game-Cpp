#pragma once
#include "../GameManager/ResourceManager.h"
#include "../GameManager/Pool.h"
#include "../GameManager/Collision.h"
#include "Lane.h"
#include "Player.h"

#define MAP Map::GetInstance()
class Map: public CSingleton<Map>
{
private:
    Pool *carPool;
    Lane lanes[10];
    int NUM_LANES;
    bool gamePaused;
    float sfxclock;
    int timeToNextSFX;

public:
    Map();
    virtual ~Map();
    void refreshTop(float dt);
    void run();
    void Draw(RenderWindow *, float dt);
    void PlaySFX(float dt);
    void PauseGame();
    void newGameRefresh();
    bool checkCollisionCarAndPlayer(Player player);
    bool checkCollisionWaterAndPlayer(Player player);
};