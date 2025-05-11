#ifndef PARTICLE_HPP
#define PARTICLE_HPP

#include <SFML/Graphics.hpp>
#include "Gravitysource.hpp"

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
    Particle(const float &pos_x, const float &pos_y, const float &vel_x, const float &vel_y, const sf::Color &color)
        : pos{pos_x, pos_y}, vel{vel_x, vel_y}
    {
        s.setRadius(4);
        s.setPosition(pos);
        s.setFillColor(color);
    }

    Particle(const float &pos_x, const float &pos_y, const float &vel_x, const float &vel_y, float value)
        : pos{pos_x, pos_y}, vel{vel_x, vel_y}
    {
        s.setRadius(4);
        s.setPosition(pos);
        if (value < 0.0f)
            value = 0;
        if (value > 1.0f)
            value = 1;
        int r = 0, g = 0, b = 0;

        if (value < 0.5f)
        {
            b = 255 * (1.0f - 2 * value);
            g = 255 * 2 * value;
        }
        else
        {
            g = 255 * (2.0f - 2 * value);
            r = 255 * (2 * value - 1);
        }
        s.setFillColor(sf::Color(r, g, b));
    }

    void update_physics(const GravitySource &src)
    {
        float dist_x = src.get_pos().x - pos.x;
        float dist_y = src.get_pos().y - pos.y;

        float dist = sqrt(dist_x * dist_x + dist_y * dist_y);
        float inv_dist = 1.f / dist;

        float norm_x = inv_dist * dist_x;
        float norm_y = inv_dist * dist_y;

        float dx = norm_x * src.get_strength() * inv_dist * inv_dist;
        float dy = norm_y * src.get_strength() * inv_dist * inv_dist;

        vel.x += dx;
        vel.y += dy;

        pos.x += vel.x;
        pos.y += vel.y;

        s.setPosition(pos);
    }
};

#endif