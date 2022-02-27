#include "StateBase.h"
#include "Menu.h"
#include "Play.h"
#include "End.h"
#include "Setting.h"
#include "About.h"


StateBase *StateBase::CreateState(StateTypes st)
{
    StateBase *gs = nullptr;
    switch (st)
    {
    case INVALID:
        break;
    case MENU:
        gs = new Menu();
        break;
    case PLAY:
        gs = new Play();
        break;
    case SETTING:
        gs = new Setting();
        break;
    case ABOUT:
        gs = new About();
        break;
    case END:
        gs = new End();
        break;
    default:
        break;
    }
    return gs;
}

StateBase::StateBase()
{
}

StateBase::~StateBase()
{
}
