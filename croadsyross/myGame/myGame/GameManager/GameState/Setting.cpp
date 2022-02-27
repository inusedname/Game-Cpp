#include "Setting.h"

Setting::Setting()
{
}

Setting::~Setting()
{
}

void Setting::Exit()
{
}

void Setting::Resume()
{
}

void Setting::Pause()
{
}

void Setting::Init()
{
	std::cout << "Init Setting\n";

	currentSettingBox = 0;
	currentOption[0] = 1;
	currentOption[1] = MP->nowPlayingIndex;
	currentOption[2] = DATA->musicVolume / 10;
	currentOption[3] = DATA->sfxVolume / 10;

	setting_bg.setTexture(*DATA->getTexture("setting_bg"));
	bg_size = Vector2f(setting_bg.getLocalBounds().width, setting_bg.getLocalBounds().height);
	setting_bg.setOrigin(bg_size.x / 2, bg_size.y / 2);
	setting_bg.setPosition(DATA->m_screenSize.x / 2, DATA->m_screenSize.y / 2);

	setting_title.setFont(*DATA->getFont("ThaleahFat"));
	setting_title.setFillColor(Color::White);
	setting_title.setCharacterSize(50);
	setting_title.setString("SETTING");
	setting_title.setOrigin(setting_title.getLocalBounds().width / 2, setting_title.getLocalBounds().height / 2);
	setting_title.setPosition(DATA->m_screenSize.x / 2, setting_bg.getPosition().y - 225);

	Text tmp;
	tmp.setFont(*DATA->getFont("m5x7"));
	tmp.setFillColor(Color::White);
	tmp.setCharacterSize(50);
	for (int i = 0; i < subSettingNum; i++)
		subSettingTitle.push_back(tmp);
	subSettingTitle[0].setString("FPS LIMIT");
	subSettingTitle[1].setString("MUSIC");
	subSettingTitle[2].setString("MUSIC VOLUME");
	subSettingTitle[3].setString("SFX VOLUME");
	for (int i = 0; i < subSettingNum; i++)
		subSettingTitle[i].setPosition(250, setting_title.getPosition().y + 50 + 50 * (i + 1));

	leftButton.setTexture(*DATA->getTexture("left_button"));
	rightButton.setTexture(*DATA->getTexture("right_button"));
	leftButton.setPosition(subSettingTitle[currentSettingBox].getPosition().x + 300, subSettingTitle[currentSettingBox].getPosition().y + 25);
	rightButton.setPosition(leftButton.getPosition().x + 450, leftButton.getPosition().y);
	leftButton.setScale(2.5, 2.5);
	rightButton.setScale(2.5, 2.5);
	volumeBar.setTexture(*DATA->getTexture("volume_bar"));
	volumeBarDark.setTexture(*DATA->getTexture("volume_bar_dark"));

	currentMusic.setFont(*DATA->getFont("m5x7"));
	currentMusic.setFillColor(Color::White);
	currentMusic.setCharacterSize(30);
	currentMusic.setString(MP->getMusic(MP->nowPlayingIndex));
	currentMusic.setOrigin(currentMusic.getLocalBounds().width / 2, currentMusic.getLocalBounds().height / 2);
	currentMusic.setPosition(leftButton.getPosition().x + ((rightButton.getPosition().x - leftButton.getPosition().x) / 2) + 12
		,subSettingTitle[1].getPosition().y + 27);

	fps_limit.push_back("30");
	fps_limit.push_back("60");
	fps_limit.push_back("Unlimited");
	currentFPS.setFont(*DATA->getFont("ThaleahFat"));
	currentFPS.setFillColor(Color::White);
	currentFPS.setCharacterSize(50);
	currentFPS.setString(fps_limit[currentOption[0]]);
	currentFPS.setOrigin(currentFPS.getLocalBounds().width / 2, currentFPS.getLocalBounds().height / 2);
	currentFPS.setPosition(leftButton.getPosition().x + ((rightButton.getPosition().x - leftButton.getPosition().x) / 2) + 12
		, subSettingTitle[0].getPosition().y + 10);
}

void Setting::Update(float deltatime, std::vector<Event> &inputFromKeyboard)
{
	bool changesSetting = false;
	for (Event ev : inputFromKeyboard)
	{
		if (ev.key.code == Keyboard::Escape)
		{
			inputFromKeyboard.pop_back();
			DATA->saveInit();
			GSM->PopState();
			break;
		}
		if (ev.key.code == Keyboard::D)
		{
			switch (currentSettingBox)
			{
			case 0:
				if (currentOption[0] < fps_limit.size() - 1)
					currentOption[0]++, changesSetting = true;
				break;
			case 1:
				if (currentOption[1] < MP->getSize() - 1)
					currentOption[1]++, changesSetting = true;
				break;
			case 2:
			case 3:
				if (currentOption[currentSettingBox] < DATA->volumeMAX)
					currentOption[currentSettingBox]++, changesSetting = true;
				break;
			default:
				break;
			}
			DATA->playSound("select_setting");
		}
		else if (ev.key.code == Keyboard::A)
		{
			if (currentOption[currentSettingBox] > 0)
			{
				currentOption[currentSettingBox]--, changesSetting = true;
				DATA->playSound("select_setting");
			}
		}
		else if (ev.key.code == Keyboard::W)
		{
			if (currentSettingBox > 0)
			{
				currentSettingBox--;
				DATA->playSound("change_tab_menu");
			}
		}
		else if (ev.key.code == Keyboard::S)
		{
			if (currentSettingBox < subSettingNum - 1)
			{
				currentSettingBox++; 
				DATA->playSound("change_tab_menu");
			}
		}
		inputFromKeyboard.pop_back();
	}
	if (currentSettingBox > 0)
		subSettingTitle[currentSettingBox - 1].setFillColor(Color::White);
	if (currentSettingBox < subSettingNum - 1)
		subSettingTitle[currentSettingBox + 1].setFillColor(Color::White);
	subSettingTitle[currentSettingBox].setFillColor(Color::Yellow);
	leftButton.setPosition(subSettingTitle[currentSettingBox].getPosition().x + 300, subSettingTitle[currentSettingBox].getPosition().y + 25);
	rightButton.setPosition(leftButton.getPosition().x + 450, leftButton.getPosition().y);
	if (changesSetting)
		switch (currentSettingBox)
		{
		case 0:
			DATA->changeFrameLimit = true;
			switch (currentOption[0])
			{
				case 0: 
					DATA->frameLimit = 30;
					break;
				case 1:
					DATA->frameLimit = 60;
					break;
				case 2:
					DATA->frameLimit = 0;
					break;
			}
			currentFPS.setString(fps_limit[currentOption[0]]);
			currentFPS.setOrigin(currentFPS.getLocalBounds().width / 2, currentFPS.getOrigin().y);
			break;
		case 1:
			DATA->stopMusic(MP->getMusic(MP->nowPlayingIndex));
			MP->nowPlayingIndex = currentOption[1];
			DATA->playMusic(MP->getMusic(MP->nowPlayingIndex));
			currentMusic.setString(MP->getMusic(MP->nowPlayingIndex));
			currentMusic.setOrigin(currentMusic.getLocalBounds().width / 2, currentFPS.getOrigin().y);
			break;
		case 2:
			DATA->musicVolume = 10 * currentOption[2];
			DATA->updateVolMusic();
			break;
		case 3:
			DATA->sfxVolume = 10 * currentOption[3];
			DATA->updateVolSound();
			break;
		}
}

void Setting::Render(RenderWindow* window)
{
	window->draw(setting_bg);
	window->draw(setting_title);
	for (int i = 0; i < subSettingNum; i++)
	{
		window->draw(subSettingTitle[i]);
	}
	window->draw(leftButton);
	window->draw(rightButton);
	
	window->draw(currentFPS);
	window->draw(currentMusic);
	DrawVolumeBars(window, 2, Vector2f(subSettingTitle[2].getLocalBounds().width + 440, subSettingTitle[2].getPosition().y + 15));
	DrawVolumeBars(window, 3, Vector2f(subSettingTitle[2].getLocalBounds().width + 440, subSettingTitle[3].getPosition().y + 15));
}

void Setting::DrawVolumeBars(RenderWindow* window, int which, Vector2f pos_start)
{
	for (int i = 0; i < currentOption[which]; i++)
	{
		volumeBarDark.setPosition(pos_start.x + 20 * i, pos_start.y);
		window->draw(volumeBarDark);
	}
	for (int i = currentOption[which]; i < DATA->volumeMAX; i++)
	{
		volumeBar.setPosition(pos_start.x + 20 * i, pos_start.y);
		window->draw(volumeBar);
	}
}
