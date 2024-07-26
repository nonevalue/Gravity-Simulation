#include "Planetary.hpp"

Planetary::Planetary(double mass, float radius, const sf::Vector2f& position)
{
    c_mass = mass;
    c_radius = radius;
    c_velocity = sf::Vector2f(0, 0);
    body.setRadius(c_radius);
    body.setOrigin(c_radius, c_radius);
    body.setPosition(position);
    body.setFillColor(sf::Color(rand()%255, rand()%255, rand()%255));
}
Planetary::Planetary(double mass, float radius, const sf::Vector2f& position, const sf::Vector2f& velocity)
{
    c_mass = mass;
    c_radius = radius;
    c_velocity = velocity;
    body.setRadius(c_radius);
    body.setOrigin(c_radius, c_radius);
    body.setPosition(position);
    body.setFillColor(sf::Color(rand()%255, rand()%255, rand()%255));
}
Planetary::Planetary(double mass, float radius, const sf::Vector2f& position, const sf::Color& color)
{
    c_mass = mass;
    c_radius = radius;
    c_velocity = sf::Vector2f(0, 0);
    body.setRadius(c_radius);
    body.setOrigin(c_radius, c_radius);
    body.setPosition(position);
    body.setFillColor(color);
}
Planetary::Planetary(double mass, float radius, const sf::Vector2f& position, const sf::Vector2f& velocity, const sf::Color& color)
{
    c_mass = mass;
    c_radius = radius;
    c_velocity = velocity;
    body.setRadius(c_radius);
    body.setOrigin(c_radius, c_radius);
    body.setPosition(position);
    body.setFillColor(color);
}

void Planetary::calcGravity(Planetary &planet)
{
    float delta_x = body.getPosition().x - planet.body.getPosition().x;
    float delta_y = body.getPosition().y - planet.body.getPosition().y;

    float angle = atan2(delta_x, delta_y);
    float hypotenuse = sqrt(pow(delta_x, 2) + pow(delta_y, 2));
    double distance = hypotenuse;

    double acceleration = G * planet.c_mass / pow(distance, 2);
    c_velocity = sf::Vector2f(-acceleration * cos(angle), -acceleration * sin(angle));
}

void Planetary::updatePosition()
{
    body.move(c_velocity);
}

void Planetary::draw(sf::RenderWindow *window)
{
    window->draw(body);
}
