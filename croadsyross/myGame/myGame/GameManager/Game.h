#pragma once
#include "ResourceManager.h"
#include "MusicPlayer.h"
#include "GameState/StateMachine.h"
#include "../Objects/Map.h"
class Game
{
private:
    RenderWindow *window;
    Event sfEvent;
    std::vector<Event> inputFromKeyboard;
    void initWindow();
    Clock dtClock;
    float dt;
    bool showGuide;
    Sprite keyboardGuide;

public:
    Game();
    ~Game();
    void updateSFMLEvents();
    void update();
    float getDT();
    void updateDT();
    void render();
    void run();
};