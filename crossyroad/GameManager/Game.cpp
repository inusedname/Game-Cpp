#include "Game.h"

Game::Game(){

};
Game::~Game()
{
}
void Game::initWindow()
{
    window = new RenderWindow(VideoMode(1280, 720), "CrossyRoad");
}