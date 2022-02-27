#include "Game.h"
#include "GameState/StateBase.h"
Game::Game()
{
	std::cout << "Map load complete\n";
	initWindow();
	GSM->ChangeState(MENU);
	showGuide = true;
	keyboardGuide.setTexture(*DATA->getTexture("keyboardguide"));
	keyboardGuide.setScale(0.6, 0.6);
	keyboardGuide.setPosition(DATA->m_screenSize.x - 250, 30);
	DATA->playMusic(MP->getMusic(MP->nowPlayingIndex));
}
Game::~Game()
{
	delete window;
}
void Game::initWindow()
{
	window = new RenderWindow(VideoMode(DATA->getScreenSize().x, DATA->getScreenSize().y), "CroadsyRoss2077");
	window->setFramerateLimit(DATA->frameLimit);
	window->setKeyRepeatEnabled(false);
}
void Game::run()
{
	while (window->isOpen())
	{
		updateDT();
		update();
		render();
	}
}
void Game::updateSFMLEvents()
{
	while (window->pollEvent(sfEvent))
	{
		if (sfEvent.type == Event::Closed)
			window->close();
		if (sfEvent.type == Event::KeyReleased)
		{
			if (sfEvent.key.code == Keyboard::H)
				DATA->showHint = !DATA->showHint;
			else
				inputFromKeyboard.push_back(sfEvent);
		}
	}
}
void Game::update()
{
	if (DATA->getMusic(MP->getMusic(MP->nowPlayingIndex))->getStatus() == SoundSource::Stopped)
	{
		if (MP->nowPlayingIndex < MP->getSize() - 1)
			MP->nowPlayingIndex++;
		else
			MP->nowPlayingIndex = 0;
		DATA->playMusic(MP->getMusic(MP->nowPlayingIndex));
	}
	if (DATA->changeFrameLimit)
	{
		window->setFramerateLimit(DATA->frameLimit);
		DATA->changeFrameLimit = false;
	}
	if (DATA->stopTheGame)
		window->close();
	updateSFMLEvents();
	if (GSM->NeedToChangeState())
		GSM->PerformStateChange();
	GSM->currentState()->Update(dt, inputFromKeyboard);
	inputFromKeyboard.clear();
}
float Game::getDT()
{
	return dt;
}
void Game::updateDT()
{
	dt = dtClock.restart().asSeconds();
}
void Game::render()
{
	window->clear();
	MAP->Draw(window, dt);
	GSM->currentState()->Render(window);
	if (DATA->showHint)
		window->draw(keyboardGuide);
	window->display();
}