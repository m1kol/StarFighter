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
        for (int i = 0; i < RObjects.size() ; ++i) {
            window.draw(RObjects[i].sprite);
        }
        window.display();
    }
    }

void Application::createObject(GameObject Obj) {
    allObjects.push_back(Obj);
}

void Application::createRObject(GameObject Obj) {
    ComponentType Test_Render = Obj.getComponent(0);
    ComponentType *ptrObj = &Test_Render;
    if(Render *R_Obj = dynamic_cast<Render*>(ptrObj)) {
        RObjects.push_back(*R_Obj);
    }
}

Application::~Application() {}

