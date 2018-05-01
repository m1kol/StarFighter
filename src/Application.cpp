#include "../headers/Application.h"
#include <SFML/Window.hpp>

Application::Application() {
    sf::RenderWindow window(sf::VideoMode(200, 200), "Game");
    ptrwindow = &window;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.display();
    }

    //создаем массив из геймобджектов AllObjects, mainloop() нужно пройтись по всем созданным объектам, проверить
    // их на наличие компоненты Render и при обнаружении запустить функцию draw()
}

Application::~Application() {}
