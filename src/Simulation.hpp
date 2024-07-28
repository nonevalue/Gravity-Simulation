#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <SFML/Graphics.hpp>

#include "EntityManager.hpp"

template<typename T>
std::string numberToString(T number)
{
    std::stringstream ss;
    ss << number;
    return ss.str();
}

template<typename T>
T stringToNumber(std::string string)
{
    T number;
    std::stringstream(string) >> number;
    return number;
}

class Simulation
{
public:
    Simulation();

private:
    void update();
    void updateSystems();
    void updateEvent();
    void draw();

    void commandCheck();
    //~Simulation();
    sf::RenderWindow window;
    sf::View main_view;

    EntityManager entity_manager;

    sf::Font font;
    
    float zoom;
    sf::Text zoom_text;
    sf::Text coordinate_text;

    int console_timer;
    std::string entered_text;
    sf::Text console_text;

    int simulation_speed;
    sf::Text speed_text;
};
