#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

enum class Side
{
    LEFT,
    RIGHT,
    NONE
};

class Branch
{
public:
    Sprite spriteBranch;
    Side positionBranch;
};
class Branches
{
public:
    std::vector<Branch> branches;

public:
    Branches(Texture &, int);
    void updateBranches(float seed);
};