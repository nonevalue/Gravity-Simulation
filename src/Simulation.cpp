#include "Simulation.hpp"

Simulation::Simulation()
{
    window.create(sf::VideoMode(600, 600), "SFML works!");
    window.setFramerateLimit(60);
    main_view.setCenter(sf::Vector2f(0,0));
    main_view.setSize(sf::Vector2f(200.f, 200.f));

    sf::Font font;
    if (!font.loadFromFile("font.ttf"))
        std::cout << "Font yuklenemedi\n";
    
    zoom = 1.f;
    zoom_text.setFont(font);
    zoom_text.setPosition(0, 0);
    zoom_text.setString("zoom: " + std::to_string(zoom));

    coordinate_text.setFont(font);
    coordinate_text.setPosition(0, 30);

    console_timer = 0;
    console_text.setFont(font);
    console_text.setPosition(0, 550);

    simulation_speed = 0;
    speed_text.setFont(font);
    speed_text.setPosition(0, 60);
    speed_text.setString("simulation speed: " + std::to_string(simulation_speed));

    entity_manager.addPlanetary(5.972e24, 6.371e6, sf::Vector2f(0.f, 0.f), sf::Color::Blue);
    entity_manager.addPlanetary(7.347e22, 1.737e6, sf::Vector2f(0, 3.844e8), sf::Vector2f(1022, 0), sf::Color::White);

    entity_manager.addPlanetary(5.972e3, 6.371e4, sf::Vector2f(4.1e7, 0.f), sf::Color::Red);

    update();
}

void Simulation::update()
{
    while (window.isOpen())
    {
        updateEvent();

        updateSystems();

        draw();
    }
}

void Simulation::updateSystems()
{
    for (int i = 0; i < simulation_speed; i++)
    {
        entity_manager.update();
    }

    window.setView(main_view);

    sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
    sf::Vector2f coordinate = window.mapPixelToCoords(mouse_pos);
    coordinate_text.setString("x: " + numberToString<float>(coordinate.x) + " y: " + numberToString<float>(coordinate.y));

    window.setView(window.getDefaultView());

    console_timer++;
    if (console_timer <= 30)
        console_text.setString(entered_text);
    else if (console_timer < 60)
        console_text.setString(entered_text + "_");
    else
        console_timer = 0;
    
}

void Simulation::updateEvent()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
        if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Up)
            {
                main_view.zoom(10.f);
                zoom *= 10.f;
                zoom_text.setString("zoom: " + numberToString<float>(zoom));
            }
            if (event.key.code == sf::Keyboard::Down)
            {
                main_view.zoom(0.1f);
                zoom *= 0.1f;
                zoom_text.setString("zoom: " + numberToString<float>(zoom));
            }
            if (event.key.code == sf::Keyboard::Backspace)
            {
                if (entered_text.size() > 0)
                    entered_text.pop_back();
            }
            if (event.key.code == sf::Keyboard::Enter)
            {
                commandCheck();
            }
            if (event.key.code == sf::Keyboard::Escape)
            {
                entered_text.clear();
            }
        }
        if (event.type == sf::Event::TextEntered)
        {
            if (event.text.unicode < 128 && event.text.unicode != 8 && event.text.unicode != 27 && event.text.unicode != 13)
                entered_text.push_back(event.text.unicode);
        }
        
    }
}

void Simulation::draw()
{
    window.clear();
    //<----main view---->
    window.setView(main_view);
    entity_manager.draw(&window);

    //<----UI view---->
    window.setView(window.getDefaultView());
    window.draw(zoom_text);
    window.draw(coordinate_text);
    window.draw(console_text);
    window.draw(speed_text);
    window.display();
}

void Simulation::commandCheck()
{
    if (entered_text.substr(0,3) == "/z " && entered_text.size() > 3)
    {
        float new_zoom = stringToNumber<float>(entered_text.substr(3));
        main_view.zoom(new_zoom/zoom);
        zoom = new_zoom;
        zoom_text.setString("zoom: " + numberToString<float>(zoom));
    }
    else if (entered_text.substr(0,3) == "/c " && entered_text.size() > 3)
    {
        std::istringstream iss(entered_text.substr(3));
        float x, y;
        iss >> x >> y;
        main_view.setCenter(x, y);
    }
    else if (entered_text.substr(0,3) == "/s " && entered_text.size() > 3)
    {
        int new_speed = stringToNumber<int>(entered_text.substr(3));
        if (new_speed > 0)
        {
            simulation_speed = new_speed;
            speed_text.setString("simulation speed: " + std::to_string(simulation_speed));
        }
    }
    entered_text.clear();
}
