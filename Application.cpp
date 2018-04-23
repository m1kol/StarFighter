#include "Application.h"
#include <SFML/Window.hpp>

void mainloop();

Application::Application() {
//    sf::RenderWindow Window(sf::VideoMode(200, 200), "Game");
    window = new sf::RenderWindow (sf::VideoMode(200, 200), "StarFighter");
    //создаем массив из геймобджектов AllObjects, mainloop() нужно пройтись по всем созданным объектам, проверить
    // их на наличие компоненты Render и при обнаружении запустить функцию draw()

    // mainloop
    while (window->isOpen()) {
        sf::Event event;
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close();
        }

        window->clear();
        //когда зароботает это, то if будет проверять массив на наличие Render и запускать отрисовку
        for (auto i = 0; i < allObjects.size(); i++) {
            std::cout << "Объект№" << i << std::endl;
            break;
        }

        window->display();
    }
}

Application* Application::p_instance = 0;