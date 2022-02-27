#pragma once
#include "../ResourceManager.h"
#include "../../Objects/Map.h"
#include "../Button.h"
#include "StateBase.h"
class Play : public StateBase
{
public:
    Play();
    virtual ~Play();

    void Exit();
    void Resume();
    void Pause();

    void Init();
    void Update(float deltatime, std::vector<Event>& inputFromKeyboard);
    void Render(RenderWindow*);
    bool gamePaused;

    void movePlayer(LR x);

private:
    Player thePlayer;
    Button buttons[6];
    bool clickWhilePause;
    int currentButton;
    Text currentScoreText;
    Text highestScoreText;
};