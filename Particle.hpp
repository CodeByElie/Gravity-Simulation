#ifndef PARTICLE_HPP
#define PARTICLE_HPP

#include <SFML/Graphics.hpp>

class Particle : public sf::Drawable
{
    sf::Vector2f pos;
    sf::Vector2f vel;
    sf::CircleShape s;

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override
    {
        target.draw(s, states);
    }

public:
    Particle(const float &pos_x, const float &pos_y, const float &vel_x, const float &vel_y)
        : pos{pos_x, pos_y}, vel{vel_x, vel_y}
    {
        s.setRadius(4);
        s.setPosition(pos);
        s.setFillColor(sf::Color::White);
    }
};

#endif