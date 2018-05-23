#include "../headers/Application.h"
#include <SFML/Window.hpp>
using namespace sf;


Application::Application() {
    ptrwindow = new RenderWindow(VideoMode(700, 700), "Game");
}

void  Application::run() {
    while (ptrwindow->isOpen())
    {
        Clock clock;
        time = clock.getElapsedTime().asMicroseconds(); //дать прошедшее время в микросекундах
        clock.restart(); //перезагружает время
        time = time/100; //скорость игры
        Event event;

        while (ptrwindow->pollEvent(event))
        {
            if (event.type == Event::Closed)
                ptrwindow->close();
        }
        Render* a = R_Objects[1];
        SIMPLEANIMATION(a->sprite)

        ptrwindow->clear();
        for (int i = 0; i < R_Objects.size() ; i++) {
            ptrwindow->draw(R_Objects[i]->sprite);
        }
        ptrwindow->display();
    }
}
//void Application::update() {
//    int a = allObjects.size();
//    for (int i = 0; i < a; i++) {
//        for (int k = 0; k < a; k++) {
//            if(i!=k){
//                std::cout << "PredCollision"<< "\n";
//                ComponentType *c = allObjects[i]->getComponent("Collider");
//                Collider *C = dynamic_cast<Collider*>(c);
//                if(C->detectCollision(allObjects[k])) {
//                    std::cout << "Collision"<< "\n";
//                }
//            }
//        }
//    }
//}

Application::~Application() {
    delete ptrwindow;
}

