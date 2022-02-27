#pragma once
#include "StateMachine.h"
#include "StateBase.h"

StateMachine::StateMachine()
{
    m_ActivesState = nullptr;
    m_NextState = nullptr;
}
StateMachine::~StateMachine()
{
    while (!m_StateStack.empty())
    {
        delete m_StateStack.back();
        m_StateStack.pop_back();
    }
}
void StateMachine::ChangeState(StateBase *state)
{
    m_NextState = state;
}

void StateMachine::ChangeState(StateTypes st)
{
    StateBase *gs = StateBase::CreateState(st);
    ChangeState(gs);
}

void StateMachine::PushState(StateTypes st)
{
    StateBase *gs = StateBase::CreateState(st);
    if (!m_StateStack.empty())
    {
        m_StateStack.back()->Pause();
    }
    m_NextState = gs;
}

void StateMachine::PopState()
{
    if (!m_StateStack.empty())
    {
        m_StateStack.back()->Exit();
        m_StateStack.pop_back();
    }
    if (!m_StateStack.empty())
    {
        m_StateStack.back()->Resume();
    }
    m_ActivesState = m_StateStack.back();
}

void StateMachine::PerformStateChange()
{
    if (m_NextState != nullptr)
    {
        if (!m_StateStack.empty())
        {
            m_StateStack.back()->Exit();
        }
        m_StateStack.push_back(m_NextState);
        m_StateStack.back()->Init();
        m_ActivesState = m_NextState;
    }
    m_NextState = nullptr;
}

StateBase *StateMachine::currentState() const
{
    return m_ActivesState;
}

StateBase *StateMachine::nextState() const
{
    return m_NextState;
}

bool StateMachine::NeedToChangeState()
{
    return m_NextState != nullptr;
}

bool StateMachine::HasState()
{
    return m_StateStack.size() > 0;
}