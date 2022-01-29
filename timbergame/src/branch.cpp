#include "branch.h"

void Branches::updateBranches(float seed)
{
    for (int i = branches.size() - 1; i > 0; i--)
        branches[i].positionBranch = branches[i - 1].positionBranch;
    // Spawn
    srand((int)time(0) + seed);
    int r = (rand() % 3);
    switch (r)
    {
    case 0:
        branches[0].positionBranch = Side::LEFT;
        break;
    case 1:
        branches[0].positionBranch = Side::RIGHT;
        break;
    default:
        branches[0].positionBranch = Side::NONE;
        break;
    }
    for (int i = 0; i < branches.size(); i++)
    {
        float height = i * 150;
        if (branches[i].positionBranch == Side::LEFT)
        {
            branches[i].spriteBranch.setPosition(600, height);
            branches[i].spriteBranch.setRotation(180);
        }
        else if (branches[i].positionBranch == Side::RIGHT)
        {
            branches[i].spriteBranch.setPosition(1330, height);
            // Screen Width / 2 + tree width / 2 + branch width / 2
            branches[i].spriteBranch.setRotation(0);
        }
        else
        {
            branches[i].spriteBranch.setPosition(3000, height);
        }
    }
}
Branches::Branches(Texture &textureBranch, int qty)
{
    branches.resize(qty);
    for (auto &&it : branches)
    {
        it.spriteBranch.setTexture(textureBranch);
        it.spriteBranch.setOrigin(220, 40);
        it.positionBranch = Side::NONE;
    }
}