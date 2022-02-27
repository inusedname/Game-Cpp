#pragma once
#include "../ResourceManager.h"
#include "StateBase.h"
class About : public StateBase
{
public:
    About();
    virtual ~About();

    void Exit();
    void Resume();
    void Pause();

    void Init();
    void Update(float deltatime, std::vector<Event> &inputFromKeyboard);
    void Render(RenderWindow*);
private:
    Sprite infoSprite;
};