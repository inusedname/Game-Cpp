#include "Map.h"
Map::Map()
{
    timeToNextSFX = (rand() % 4) + 5;
    sfxclock = 0;
    gamePaused = false;
    carPool = new Pool();
    NUM_LANES = 6;
    for (int i = 1; i <= 3; i++)
    {
        lanes[i].setLanePosition(Vector2f(0, DATA->getScreenSize().y - (128 * i)));
        lanes[i].refreshSafe();
    } // 3 dòng đầu tiên sẽ là chỗ bắt đầu
    for (int i = 4; i <= NUM_LANES + 1; i++)
        // nếu chỉ tới NUM_LANES thì sẽ gặp vấn đề xe chưa kịp vẽ thì người đã chạy -> +1
    {
        lanes[i].setLanePosition(Vector2f(0, DATA->getScreenSize().y - (128 * i)));
        lanes[i].refresh();
    }
}
void Map::newGameRefresh()
{
    DATA->currentScore = 0;
    gamePaused = false;
    for (int i = 1; i <= 3; i++)
    {
        lanes[i].refreshSafe();
    } // 3 dòng đầu tiên sẽ là chỗ bắt đầu
    for (int i = 4; i <= NUM_LANES + 1; i++)
        // nếu chỉ tới NUM_LANES thì sẽ gặp vấn đề xe chưa kịp vẽ thì người đã chạy -> +1
    {
        lanes[i].refresh();
    }
}
bool Map::checkCollisionCarAndPlayer(Player player)
{
    bool touch = false;
    if (lanes[2].getLaneProperty() == NORMAL || lanes[2].getLaneProperty() == SPECIAL)
    {
        touch = lanes[2].carsAndPlayerCollision(player);
    }
    return touch;
}
bool Map::checkCollisionWaterAndPlayer(Player player)
{
    bool touch = false;
    if (lanes[2].getLaneProperty() == WATER)
    {
        touch = lanes[2].waterAndPlayerCollision(player);
    }
    return touch;
}
Map::~Map()
{
    delete carPool;
}
void Map::Draw(RenderWindow *window, float dt)
{
    for (int i = 1; i <= NUM_LANES; i++)
        lanes[i].DrawLane(window);
    if (gamePaused == false)
    {
        for (int i = NUM_LANES + 1; i >= 1; i--)
        {
            lanes[i].DrawCars(window, dt, i);
        }
        PlaySFX(dt);
    }
    else 
        for (int i = NUM_LANES + 1; i >= 1; i--)
            lanes[i].DrawCars(window, 0, i);
    for (int i = NUM_LANES + 1; i >= 1; i--)
        lanes[i].DrawLeaf(window);
}
void Map::PlaySFX(float dt)
{
    sfxclock += dt;
    if (sfxclock >= timeToNextSFX)
    {
        if (rand() % 2)
            DATA->playSound("bird_chipping");
        else
            DATA->playSound("car_horn");
        timeToNextSFX = (rand() % 4) + 5;
        sfxclock = 0;
    }
}
void Map::refreshTop(float dt)
{
    for (int i = NUM_LANES + 1; i > 1; i--)
    {
        lanes[i].setLanePosition(lanes[i - 1].getLanePosition());
    }
    for (int i = 2; i <= NUM_LANES + 1; i++)
    {
        lanes[i - 1] = lanes[i];
    }
    lanes[NUM_LANES + 1].setLanePosition(Vector2f(0, -128));
    lanes[NUM_LANES + 1].refresh();
}

void Map::run()
{
}
void Map::PauseGame()
{
    gamePaused = !gamePaused;
}