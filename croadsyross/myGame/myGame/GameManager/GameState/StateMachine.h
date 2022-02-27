#pragma once
#include "../ResourceManager.h"

#define GSM StateMachine::GetInstance()

class StateBase;

enum StateTypes
{
    INVALID = 0,
    MENU,
    PLAY,
    SETTING,
    ABOUT,
    END,
};
class StateMachine : public CSingleton<StateMachine>
{
private:
    std::list<StateBase *> m_StateStack;
    StateBase *m_ActivesState;
    StateBase *m_NextState;

public:
    StateMachine();
    ~StateMachine();
    void ChangeState(StateBase *state);
    void ChangeState(StateTypes st);
    void PushState(StateTypes st);
    void PopState();

    void PerformStateChange();

    StateBase *currentState() const;
    StateBase *nextState() const;
    bool NeedToChangeState();
    bool HasState();
};