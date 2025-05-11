#include <SFML/Graphics.hpp>
#include "Gravitysource.hpp"

int main()
{

    sf::RenderWindow window(sf::VideoMode({1280, 720}), "Gravity Simulation");

    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();

        window.display();
    }

    return 0;
}