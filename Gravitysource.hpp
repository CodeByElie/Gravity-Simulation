#ifndef GRAVITYSOURCE_HPP
#define GRAVITYSOURCE_HPP

#include <SFML/Graphics.hpp>

class GravitySource : public sf::Drawable
{
    sf::Vector2f pos;
    float strength;
    sf::CircleShape s;

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override
    {
        target.draw(s, states);
    }

public:
    GravitySource(const float &pos_x, const float &pos_y, const float &strength)
        : pos{pos_x, pos_y}, strength{strength}
    {
        s.setRadius(4);
        s.setPosition(pos);
        s.setFillColor(sf::Color::White);
    }

    sf::Vector2f get_pos() const
    {
        return pos;
    }

    float get_strength() const
    {
        return strength;
    }
};

#endif