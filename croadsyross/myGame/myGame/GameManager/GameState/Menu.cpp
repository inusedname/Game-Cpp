#include "Menu.h"

Menu::Menu()
{
}

Menu::~Menu()
{
}

void Menu::Exit()
{
}

void Menu::Resume()
{
}

void Menu::Pause()
{
}

void Menu::Init()
{
	wait1second = false;
	menuTime = 0;
	std::cout << "Init Menu\n";
	gameTitle.setFont(*DATA->getFont("ThaleahFat"));
	gameTitle.setFillColor(Color::White);
	gameTitle.setOutlineColor(Color(78, 119, 154));
	gameTitle.setOutlineThickness(3);
	gameTitle.setCharacterSize(150);
	gameTitle.setString("CROADSY ROSS");
	gameTitle.setOrigin(gameTitle.getLocalBounds().width / 2, gameTitle.getLocalBounds().height / 2);
	gameTitle.setPosition(DATA->m_screenSize.x / 2, 100);

	allButtons.push_back(Button("play"));
	allButtons.push_back(Button("setting"));
	allButtons.push_back(Button("about"));
	allButtons.push_back(Button("exit"));

	buttonTranscript.push_back(newButtonTranscipt("PLAY"));
	buttonTranscript.push_back(newButtonTranscipt("SETTING"));
	buttonTranscript.push_back(newButtonTranscipt("ABOUT"));
	buttonTranscript.push_back(newButtonTranscipt("EXIT"));

	currentButtonPointedTo = 0;
	allButtons[(currentButtonPointedTo + 4) % 4].setPosition(currentButtonPosition);
	updateTheLeftButton();
	updateTheRightButton();
}

void Menu::updateTheLeftButton()
{
	allButtons[(currentButtonPointedTo - 1 + 4) % 4].setPosition(Vector2f(currentButtonPosition.x - 350, currentButtonPosition.y));
	allButtons[(currentButtonPointedTo - 1 + 4) % 4].Smaller();
}

void Menu::updateTheRightButton()
{
	allButtons[(currentButtonPointedTo + 1 + 4) % 4].setPosition(Vector2f(currentButtonPosition.x + 350, currentButtonPosition.y));
	allButtons[(currentButtonPointedTo + 1 + 4) % 4].Smaller();
}

Text Menu::newButtonTranscipt(std::string msg)
{
	Text tmp;
	tmp.setFont(*DATA->getFont("m5x7"));
	tmp.setFillColor(Color::White);
	// gameTitle.setOutlineColor(Color(78, 119, 154));
	// gameTitle.setOutlineThickness(3);
	tmp.setCharacterSize(50);
	tmp.setString(msg);
	tmp.setOrigin(tmp.getLocalBounds().width / 2, tmp.getLocalBounds().height / 2);
	tmp.setPosition(DATA->m_screenSize.x / 2, currentButtonPosition.y + 80);
	return tmp;
}

void Menu::Update(float deltatime, std::vector<Event> &inputFromKeyboard)
{
	if (clicked && menuTime - menuTimeBefore >= 0.1)
	{
		menuTimeBefore = 0;
		allButtons[(currentButtonPointedTo + 4) % 4].Release();
		clicked = false;
	}
	menuTime += deltatime;
	bool changes = false;
	for (Event ev: inputFromKeyboard)
	{
		if (ev.key.code == Keyboard::D)
		{
			currentButtonPointedTo++;
			currentButtonPointedTo %= 4;
			changes = true;
			DATA->playSound("change_tab_menu");
		}
		else if (ev.key.code == Keyboard::A)
		{
			currentButtonPointedTo--;
			if (currentButtonPointedTo == -3)
				currentButtonPointedTo = 1;
			changes = true;
			DATA->playSound("change_tab_menu");
		}
		else if (ev.key.code == Keyboard::W)
		{
			switch ((currentButtonPointedTo + 4) % 4)
			{
			case 0:
				GSM->ChangeState(PLAY);
				break;
			case 1:
				GSM->ChangeState(SETTING);
				break;
			case 2:
				GSM->ChangeState(ABOUT);
				break;
			case 3:
				DATA->stopTheGame = true;
				break;
			default:
				break;
			}
			DATA->playSound("select_setting");
			allButtons[(currentButtonPointedTo + 4) % 4].Click();
			menuTimeBefore = menuTime;
			clicked = true;
		}
	}
	if (changes == true)
	{
		allButtons[(currentButtonPointedTo - 2 + 4) % 4].Bigger();
		allButtons[(currentButtonPointedTo + 4) % 4].Bigger();
		allButtons[(currentButtonPointedTo + 4) % 4].setPosition(currentButtonPosition);
		updateTheLeftButton();
		updateTheRightButton();
	}
}

void Menu::Render(RenderWindow* window)
{	
	// draw the middle button (currentbutton):
	allButtons[(currentButtonPointedTo + 4) % 4].Draw(window);
	//draw the game title
	window->draw(gameTitle);
	// draw the left and the right one
	allButtons[(currentButtonPointedTo - 1 + 4) % 4].Draw(window);
	allButtons[(currentButtonPointedTo + 1 + 4) % 4].Draw(window);
	// draw the button transcript
	window->draw(buttonTranscript[(currentButtonPointedTo + 4) % 4]);
}