#include "Play.h"

Play::Play()
{
}

Play::~Play()
{
}

void Play::Exit()
{
}

void Play::Resume()
{
}

void Play::Pause()
{
}

void Play::Init()
{
	DATA->currentScore = 0;
	clickWhilePause = false;
	currentButton = 1;
	gamePaused = false;

	buttons[0] = Button("setting_white");
	buttons[1] = Button("retry_white");
	buttons[2] = Button("exit_white");
	buttons[3] = Button("setting");
	buttons[4] = Button("retry");
	buttons[5] = Button("exit");
	
	currentScoreText.setFont(*DATA->getFont("ThaleahFat"));
	currentScoreText.setCharacterSize(120);
	currentScoreText.setFillColor(Color::White);
	currentScoreText.setString("0");
	currentScoreText.setPosition(100, 5);

	highestScoreText.setFont(*DATA->getFont("ThaleahFat"));
	highestScoreText.setCharacterSize(75);
	highestScoreText.setFillColor(Color::White);
	highestScoreText.setString("TOP " + std::to_string(DATA->highestScore));
	highestScoreText.setPosition(100, 110);

	for (int i = 0; i < 6; i++)
	{
		buttons[i].setScale(0.5);
	}
	for (int i = 0; i < 3; i++)
	{
		buttons[i].setPosition(Vector2f(DATA->m_screenSize.x / 2 + (300 * (i - 1)), DATA->m_screenSize.y / 2));
		buttons[i + 3].setPosition(buttons[i].getPosition());
	}
}

void Play::Update(float deltatime, std::vector<Event> &inputFromKeyboard)
{
	for (Event ev : inputFromKeyboard)
	{
		if (ev.key.code == Keyboard::W)
		{
			if (gamePaused)
			{
				clickWhilePause = true;
			}
			else
			{
				DATA->currentScore++;
				MAP->refreshTop(deltatime);
			}
		}
		else if (ev.key.code == Keyboard::A)
		{
			if (gamePaused)
			{
				if (currentButton > 0)
				{
					currentButton--;
					DATA->playSound("change_tab_menu");
				}
			}
			else
			{
				movePlayer(TOTHELEFT);
			}
		}
		else if (ev.key.code == Keyboard::D)
		{
			if (gamePaused)
			{
				if (currentButton < 2)
				{
					currentButton++;
					DATA->playSound("change_tab_menu");
				}
			}
			else
			{
				movePlayer(TOTHERIGHT);
			}
		}
		else if (ev.key.code == Keyboard::Escape)
		{
			MAP->PauseGame();
			gamePaused = !gamePaused;
		}
		inputFromKeyboard.clear();
		
		if (clickWhilePause)
		{
			DATA->playSound("select_setting");
			switch (currentButton)
			{
				case 0: 
					GSM->PushState(SETTING);
					break;
				case 1:
					MAP->newGameRefresh();
					gamePaused = false;
					break;
				case 2:
					GSM->PopState();
					break;
				default:
					break;
			}
			clickWhilePause = false;
		}
	}
	MAP->run();
	currentScoreText.setString(std::to_string(DATA->currentScore));
	if (MAP->checkCollisionCarAndPlayer(thePlayer) || MAP->checkCollisionWaterAndPlayer(thePlayer))
	{
		DATA->playSound("die");
		if (DATA->currentScore > DATA->highestScore)
		{
			DATA->highestScore = DATA->currentScore;
			highestScoreText.setString("TOP " + std::to_string(DATA->currentScore));
			DATA->saveInit();
		}
		inputFromKeyboard.clear();
		GSM->ChangeState(END);
	}
}
void Play::movePlayer(LR x)
{
	thePlayer.move(x);
}
void Play::Render(RenderWindow* window)
{
	if (gamePaused)
	{
		buttons[currentButton + 3].Draw(window);
		if (currentButton == 0)
			buttons[1].Draw(window), buttons[2].Draw(window);
		else if (currentButton == 1)
			buttons[0].Draw(window), buttons[2].Draw(window);
		else
			buttons[0].Draw(window), buttons[1].Draw(window);
	}
	else
	{
		
		window->draw(currentScoreText);
		window->draw(highestScoreText);
		thePlayer.DrawPlayer(window);
	}
}
