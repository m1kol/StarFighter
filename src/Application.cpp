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
        for (int i = 0; i < RObjects.size() ; i++) {
            ptrwindow->draw(RObjects[i].sprite);
        }
        ptrwindow->display();
    }
}


void Application::createObject(GameObject Obj) {
    allObjects.push_back(Obj);
}

void Application::createRObject(GameObject Obj) {
    std::cout << "Here!";
    fflush(0);

    ComponentType *st = Obj.getComponent(0);
    std::cout << st->str << "String" << "\n";

//    ComponentType Test_Render = Obj.getComponent(0);
    ComponentType *ptrObj = Obj.getComponent(0);


    Render *R_Obj = (Render*) ptrObj;
    std::cout << "\n\nR_Obj == " << R_Obj << std::endl << Obj.components.size() << "\n";
    if(R_Obj) {
        std::cout << "Found!";
        std::cout << R_Obj->texture.getSize().x;
        fflush(0);
        RObjects.push_back(*R_Obj);
    }
}

Application::~Application() {
    delete ptrwindow;
}

