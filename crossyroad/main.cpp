#pragma once
#include "GameManager/ResourceManager.h"

int main()
{
    RenderWindow window(VideoMode(1280, 720), "CrossyRoad");
    Clock clk;
    while (window.isOpen())
    {
        float dt = clk.restart().asSeconds();
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
            window.clear(Color::White);
            window.display();
        }
    }
}