#pragma once
#include "../ResourceManager.h"
#include "../Button.h"
#include "StateBase.h"
class Menu : public StateBase
{
public:
    Menu();
    virtual ~Menu();

    void Exit();
    void Resume();
    void Pause();

    void Init();
    void Update(float deltatime, std::vector<Event>& inputFromKeyboard);
    void Render(RenderWindow*);

    void updateTheLeftButton();
    void updateTheRightButton();

    Text newButtonTranscipt(std::string msg);
private:
    float menuTime;
    float menuTimeBefore;
    Text gameTitle;
    std::vector<Text> buttonTranscript;
    std::vector<Button> allButtons;
    bool wait1second;
    bool clicked;
    int currentButtonPointedTo;
    Vector2f currentButtonPosition = Vector2f(DATA->m_screenSize.x / 2, 600);
};