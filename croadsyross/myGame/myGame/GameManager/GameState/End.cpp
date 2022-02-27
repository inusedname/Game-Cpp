#pragma once
#include "End.h"
#include "../../Objects/Map.h"
End::End()
{
}

End::~End()
{
}

void End::Exit()
{
}

void End::Resume()
{
}

void End::Pause()
{
}

void End::Init()
{
	clickWhilePause = false;
	std::cout << "Init End\n";
	Color x = Color::Black;
	x.a = 175;
	dead_bg.setFillColor(x);
	dead_bg.setSize(Vector2f(DATA->m_screenSize.x, DATA->m_screenSize.y - 100));
	dead_bg.setOrigin(Vector2f(dead_bg.getSize().x / 2, dead_bg.getSize().y / 2));
	dead_bg.setPosition(Vector2f(DATA->m_screenSize.x / 2, DATA->m_screenSize.y / 2));

	yourScore.setFont(*DATA->getFont("ThaleahFat"));
	yourScore.setCharacterSize(200);
	yourScore.setFillColor(Color::White);
	yourScore.setString(std::to_string(DATA->currentScore));
	yourScore.setOrigin(Vector2f(yourScore.getLocalBounds().width / 2, yourScore.getLocalBounds().height / 2));
	yourScore.setPosition(DATA->m_screenSize.x / 2, 125);

	highestScore.setFont(*DATA->getFont("ThaleahFat"));
	highestScore.setCharacterSize(100);
	highestScore.setFillColor(Color::White);
	highestScore.setString("TOP " + std::to_string(DATA->highestScore));
	highestScore.setOrigin(Vector2f(highestScore.getLocalBounds().width / 2, highestScore.getLocalBounds().height / 2));
	highestScore.setPosition(DATA->m_screenSize.x / 2, 300);

	for (int i = 0; i < 2; i++)
	{
		descriptionText[i].setFont(*DATA->getFont("m5x7"));
		descriptionText[i].setCharacterSize(75);
		descriptionText[i].setFillColor(Color::White);
		descriptionText[i].setPosition(DATA->m_screenSize.x / 2, 425);
	}
	descriptionText[0].setString(":ohhhhh: high score luon qua da!");
	descriptionText[0].setOrigin(Vector2f(descriptionText[0].getLocalBounds().width / 2, descriptionText[0].getLocalBounds().height / 2));
	descriptionText[1].setString("con choi la con go");
	descriptionText[1].setOrigin(Vector2f(descriptionText[1].getLocalBounds().width / 2, descriptionText[1].getLocalBounds().height / 2));

	buttons[0] = Button("retry_white");
	buttons[1] = Button("exit_white");
	buttons[2] = Button("retry");
	buttons[3] = Button("exit");

	for (int i = 0; i < 4; i++)
	{
		buttons[i].setScale(0.5);
	}
	for (int i = 0; i < 2; i++)
	{
		buttons[i].setPosition(Vector2f(DATA->m_screenSize.x / 2 + (150 * (2 * i - 1)), 600));
		buttons[i + 2].setPosition(buttons[i].getPosition());
	}

}

void End::Update(float deltatime, std::vector<Event> &inputFromKeyboard)
{
	for (Event ev : inputFromKeyboard)
	{
		if (ev.key.code == Keyboard::W)
		{
			clickWhilePause = true;
		}
		else if (ev.key.code == Keyboard::A)
		{
			if (currentButton > 0)
			{
				currentButton--;
				DATA->playSound("change_tab_menu");
			}
		}
		else if (ev.key.code == Keyboard::D)
		{
			if (currentButton < 1)
			{
				currentButton++;
				DATA->playSound("change_tab_menu");
			}
		}
		inputFromKeyboard.pop_back();

		if (clickWhilePause)
		{
			DATA->playSound("select_setting");
			switch (currentButton)
			{
			case 0:
				MAP->newGameRefresh();
				GSM->PopState();
				break;
			case 1:
				MAP->newGameRefresh();
				GSM->PopState();
				GSM->PopState();
				break;
			default:
				break;
			}
			clickWhilePause = false;
		}
	}
}

void End::Render(RenderWindow* window)
{
	window->draw(dead_bg);
	window->draw(yourScore);
	window->draw(highestScore);
	if (DATA->currentScore == DATA->highestScore)
		window->draw(descriptionText[0]);
	else
		window->draw(descriptionText[1]);
	buttons[currentButton + 2].Draw(window);
	if (currentButton == 0)
		buttons[1].Draw(window);
	else
		buttons[0].Draw(window);
}
