#include "GameManager/ResourceManager.h"
float const PI = 3.1456;
using namespace sf;

int main()
{
    srand(time(NULL));
    RenderWindow window(VideoMode(DATA->getScreenSize().x, DATA->getScreenSize().y), "Crossy Craft");
    Clock clk;
    while (window.isOpen())
    {
        float dt = clk.restart().asSeconds();
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
    }
}