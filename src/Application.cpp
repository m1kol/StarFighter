#include "../headers/Application.h"
#include <SFML/Window.hpp>


Application::Application() {
    ptrwindow = new sf::RenderWindow(sf::VideoMode(700, 700), "Game");
}

void  Application::run() {
    while (ptrwindow->isOpen())
    {
        sf::Event event;

        while (ptrwindow->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                ptrwindow->close();
        }

        ptrwindow->clear();
        for (int i = 0; i < R_Objects.size() ; i++) {
            ptrwindow->draw(R_Objects[i]->sprite);
        }
        ptrwindow->display();
    }
}


Application::~Application() {
    delete ptrwindow;
}

