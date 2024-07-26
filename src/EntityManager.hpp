#pragma once

#include <vector>
#include <SFML/Graphics.hpp>

#include "Planetary.hpp"

class EntityManager
{
public:
    void addPlanetary(double mass, float radius, const sf::Vector2f& position);
    void addPlanetary(double mass, float radius, const sf::Vector2f& position, const sf::Vector2f& velocity);
    void addPlanetary(double mass, float radius, const sf::Vector2f& position, const sf::Color& color);
    void addPlanetary(double mass, float radius, const sf::Vector2f& position, const sf::Vector2f& velocity, const sf::Color& color);

    void update();
    void draw(sf::RenderWindow* window);
    
    ~EntityManager();
private:
    std::vector<Planetary*> planetaries;
};