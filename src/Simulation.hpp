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



class Simulation
{
public:
    Simulation();

private:
    void update();
    void updateEvent();
    void draw();

    void commandCheck();
    //~Simulation();
    sf::RenderWindow window;
    sf::View main_view;

    EntityManager entity_manager;

    float zoom;

    sf::Font font;
    sf::Text zoom_text;
    sf::Text coordinate_text;

    std::string entered_text;
    sf::Text console_text;
    int console_timer;
};
