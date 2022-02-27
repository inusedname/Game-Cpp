#pragma once
#include "../ResourceManager.h"
#include "StateMachine.h"
class StateBase
{
public:
	StateBase();
	virtual ~StateBase();

	virtual void Exit() = 0;
	virtual void Pause() = 0;
	virtual void Resume() = 0;

	virtual void Init() = 0;
	virtual void Update(float deltaTime, std::vector<Event> &inputFromKeyboard) = 0;
	virtual void Render(sf::RenderWindow *window) = 0;

	static StateBase *CreateState(StateTypes st);
};