#pragma once
#include "ResourceManager.h"
class Game
{
private:
    RenderWindow *window;
    Event sfEvent;
    void initWindow();

public:
    Game();
    ~Game();
    void updateSFMLEvents();
    void update();
    void render();
    void run();
};