#ifndef SINGLETONE_APPLICATION_H
#define SINGLETONE_APPLICATION_H

#include <SFML/Graphics.hpp>
#include <memory>
//#include "GameObject.h"
#include <iostream>

//Класс синглтон, который дает возможность создать единственное окно, в котором будут происходить все действия и отрисовываться объекты
class Application {

private:
    sf::RenderWindow* ptrwindow;
    Application();
    ~Application();


//    Application(const  Application&) = delete;
//    Application& operator=(const Application&) = delete;

//    void* operator delete(void*) = delete;
//    void*operator delete[](void*) = delete;

public:
    static Application& getInst() {
        static Application object;
        return object;
    }
//    std::vector<GameObject*> allObjects;

    sf::RenderWindow* getWindow() {
        return Application::ptrwindow;
    }
};




#endif //SINGLETONE_APPLICATION_H
