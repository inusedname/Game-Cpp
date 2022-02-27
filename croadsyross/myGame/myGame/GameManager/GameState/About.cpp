#include "About.h"

About::About()
{
}

About::~About()
{
}

void About::Exit()
{
}

void About::Resume()
{
}

void About::Pause()
{
}

void About::Init()
{
	std::cout << "Init About\n";
	infoSprite.setTexture(*DATA->getTexture("about_page"));
	infoSprite.setOrigin(infoSprite.getLocalBounds().width / 2, infoSprite.getLocalBounds().height / 2);
	infoSprite.setPosition(DATA->m_screenSize.x / 2, DATA->m_screenSize.y / 2);
}

void About::Update(float deltatime, std::vector<Event> &inputFromKeyboard)
{
	for (Event ev : inputFromKeyboard)
	{
		if (ev.key.code == Keyboard::Escape)
		{
			inputFromKeyboard.pop_back();
			GSM->PopState();
			break;
		}
	}
}

void About::Render(RenderWindow* window)
{
	window->draw(infoSprite);
}
