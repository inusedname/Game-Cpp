#pragma once
#include "../ResourceManager.h"
#include "StateBase.h"
#include "../Button.h"
class End : public StateBase
{
public:
    End();
    virtual ~End();

    void Exit();
    void Resume();
    void Pause();

    void Init();
    void Update(float deltatime, std::vector<Event> &inputFromKeyboard);
    void Render(RenderWindow*);
private:
    int currentButton = 0;
    bool clickWhilePause;
    Button buttons[4];
    RectangleShape dead_bg;
    Text yourScore;
    Text highestScore;
    Text descriptionText[2];
};