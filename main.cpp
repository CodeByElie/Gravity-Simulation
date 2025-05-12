#include <SFML/Graphics.hpp>
#include "Particle.hpp"
#include <vector>

int main()
{

    sf::RenderWindow window(sf::VideoMode({800, 800}), "Gravity Simulation");

    window.setFramerateLimit(60);

    std::vector<Particle> particles;
    particles.push_back(Particle{1, 200, 200, 4, 0, 0, 1});
    particles.push_back(Particle{3, 400, 400, 0, 0, 10000, 0});
    particles.push_back(Particle{2, 200, 700, 1, 0, 0, 1});

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();

        for (auto &particle : particles)
        {
            particle.update_physics(particles);
            window.draw(particle);
        }

        window.display();
    }

    return 0;
}