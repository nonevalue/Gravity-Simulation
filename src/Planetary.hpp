#pragma once

#include <iostream>
#include <vector>
#include <cmath>
#include <SFML/Graphics.hpp>

const double G = 6.6743e-11;

class Planetary
{
public:
    Planetary(double mass, float radius, const sf::Vector2f& position);
    Planetary(double mass, float radius, const sf::Vector2f& position, const sf::Vector2f& velocity);
    Planetary(double mass, float radius, const sf::Vector2f& position, const sf::Color& color);
    Planetary(double mass, float radius, const sf::Vector2f& position, const sf::Vector2f& velocity, const sf::Color& color);

    void calcGravity(Planetary& planet);
    void updatePosition(std::vector<Planetary*> planetaries);
    sf::Vector2f getVelocity();

    void draw(sf::RenderWindow* window);
private:
    float getHypotenuse(float x, float y);
    double c_mass;
    float c_radius;
    sf::Vector2f c_velocity;

    sf::CircleShape body;
};