#pragma once
#include "../GameManager/ResourceManager.h"
#include "../GameManager/Pool.h"
#include "../GameManager/Collision.h"
#include "Player.h"
#include "Leaf.h"
class Lane
{
private:
    Sprite laneSprite;
    std::vector<int> tilePos;
    DIRECTION laneDirection;
    LANE_PROPERTY laneProperty; // Water or Normal/Special or None
    Collision collisionChecker;

    // for cars lanes
    int numCars;
    std::deque<std::pair<int, float>> carsProperty;
    float carSpeed;
    float timeCounter;
    float timeToNextSpawn;

    // for water lanes
    int numLeafs;
    std::vector<int> leafs;
    

public:
    Lane();
    ~Lane();
    void refresh();
    void refreshSafe();
    void setLanePosition(Vector2f);
    Vector2f getLanePosition();
    LANE_PROPERTY getLaneProperty();

    void genCar();
    bool carsAndPlayerCollision(Player);
    bool waterAndPlayerCollision(Player);

    void DrawLane(RenderWindow*);
    void DrawCars(RenderWindow*, float dt, int i);
    void DrawLeaf(RenderWindow*);
};