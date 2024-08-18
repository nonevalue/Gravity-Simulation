#include "EntityManager.hpp"

void EntityManager::addPlanetary(double mass, float radius, const sf::Vector2f &position)
{
    Planetary* temp = new Planetary(mass, radius, position);
    planetaries.push_back(temp);
}
void EntityManager::addPlanetary(double mass, float radius, const sf::Vector2f &position, const sf::Vector2f &velocity)
{
    Planetary* temp = new Planetary(mass, radius, position, velocity);
    planetaries.push_back(temp);
}
void EntityManager::addPlanetary(double mass, float radius, const sf::Vector2f &position, const sf::Color &color)
{
    Planetary* temp = new Planetary(mass, radius, position, color);
    planetaries.push_back(temp);
}
void EntityManager::addPlanetary(double mass, float radius, const sf::Vector2f &position, const sf::Vector2f &velocity, const sf::Color &color)
{
    Planetary* temp = new Planetary(mass, radius, position, velocity, color);
    planetaries.push_back(temp);
}

void EntityManager::update()
{
    std::cout << "Gravity:\n";
    for (unsigned int i = 0; i < planetaries.size(); i++)
    {
        for (unsigned int j = 0; j < planetaries.size(); j++)
        {
            if (i == j)
                continue;

            if (i == 0)
                std::cout << "Earth: " ;
            else if (i == 1)
                std::cout << "Moon: ";

            planetaries[i]->calcGravity(*planetaries[j]);
        }
    }
    std::cout << "----------\n";
    for (unsigned int i = 0; i < planetaries.size(); i++)
    {
        planetaries[i]->updatePosition(planetaries);
    }
}

void EntityManager::draw(sf::RenderWindow *window)
{
    for (unsigned int i = 0; i < planetaries.size(); i++)
    {
        planetaries[i]->draw(window);   
    }
}

EntityManager::~EntityManager()
{
    for (unsigned int i = 0; i < planetaries.size(); i++)
        delete planetaries[i];

    planetaries.clear();
}
