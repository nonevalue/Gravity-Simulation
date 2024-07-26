#include "Simulation.hpp"

Simulation::Simulation()
{
    window.create(sf::VideoMode(600, 600), "SFML works!");
    window.setFramerateLimit(60);
    main_view.setCenter(sf::Vector2f(0,0));
    main_view.setSize(sf::Vector2f(200.f, 200.f));

    zoom = 1.f;

    console_timer = 0;

    sf::Font font;
    if (!font.loadFromFile("font.ttf"))
        std::cout << "Font yuklenemedi\n";
    
    zoom_text.setFont(font);
    zoom_text.setPosition(0, 0);
    zoom_text.setString("zoom: " + std::to_string(zoom));

    coordinate_text.setFont(font);
    coordinate_text.setPosition(0, 30);

    console_text.setFont(font);
    console_text.setPosition(0, 550);

    entity_manager.addPlanetary(5.972e24, 6.371e6, sf::Vector2f(0.f, 00.f), sf::Color::Blue);
    entity_manager.addPlanetary(7.347e22, 1.737e6, sf::Vector2f(1e7, 1e7), sf::Color::White);

    update();
}

void Simulation::update()
{
    while (window.isOpen())
    {
        updateEvent();

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

        draw();
    }
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
                std::cout << "ENTER!\n";
                commandCheck();
            }
            if (event.key.code == sf::Keyboard::Escape)
            {
                entered_text = std::string();
            }
        }
        if (event.type == sf::Event::TextEntered)
        {
            if (event.text.unicode < 128 && event.text.unicode != 8 && event.text.unicode != 27)
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
    window.display();
}

void Simulation::commandCheck()
{
    //int new_zoom = stringToNumber<float>(entered_text);
    entered_text = std::string();

    //main_view.zoom(new_zoom/zoom);
    //zoom = new_zoom;
    //zoom_text.setString("zoom: " + numberToString<float>(zoom));

    //if (entered_text.substr(0,2) == "/z")
}
