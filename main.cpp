#include <SFML/Graphics.hpp>
#include "Particle.hpp"
#include <vector>

int main()
{

    sf::RenderWindow window(sf::VideoMode({600, 600}), "Gravity Simulation");

    window.setFramerateLimit(60);

    std::vector<Particle> particles;
    particles.push_back(Particle{1, 300, 300, 0, 0, pow(10,4), sf::Color::White});
    double G = 6.674;
    double speed =sqrt(G*pow(10,-7)/100)*100000;
    particles.push_back(Particle{2, 300, 200, speed, 0,0, 0.5});
    speed =sqrt(G*pow(10,-7)/200)*100000;
    particles.push_back(Particle{2, 300, 600, -speed, 0,0, 0.25});
    speed =sqrt(G*pow(10,-7)/150)*100000;
    particles.push_back(Particle{2, 300, 500, speed, 0,0, 0.75});

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