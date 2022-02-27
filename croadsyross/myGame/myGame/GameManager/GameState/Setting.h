#pragma once
#include "../ResourceManager.h"
#include "../MusicPlayer.h"
#include "StateBase.h"
class Setting : public StateBase
{
public:
    Setting();
    virtual ~Setting();

    void Exit();
    void Resume();
    void Pause();

    void Init();
    void Update(float deltatime, std::vector<Event>& inputFromKeyboard);
    void Render(RenderWindow*);
    Vector2f bg_size;

    void DrawVolumeBars(RenderWindow* window, int which, Vector2f pos_start);
private:
    const int subSettingNum = 4;
    Sprite setting_bg;
    Text setting_title;
    int currentSettingBox;
    int currentOption[4];

    std::vector<std::string> fps_limit;
    Text currentFPS;
    Text currentMusic;
    std::vector<Text> subSettingTitle;
    Sprite leftButton, rightButton;
    Sprite volumeBar, volumeBarDark;
};