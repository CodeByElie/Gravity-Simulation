#include <SFML/Graphics.hpp>
#include "Gravitysource.hpp"
#include "Particle.hpp"
#include <vector>
#include <random>

int main()
{

    sf::RenderWindow window(sf::VideoMode({800, 800}), "Gravity Simulation");

    window.setFramerateLimit(60);

    GravitySource source(400, 400, 8000);

    std::vector<Particle> particles;
    int nbParticles = 2000;

    particles.push_back(Particle{200, 200, 3, 0, 0.5});

    for (int i = 0; i < nbParticles; i++)
    {
        particles.push_back(Particle{200, 200, 3 + (i * 2. / nbParticles), 0, i / (nbParticles * 1.0f)});
    }

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
            particle.update_physics(source);
            window.draw(particle);
        }
        window.draw(source);

        window.display();
    }

    return 0;
}