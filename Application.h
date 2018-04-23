#ifndef SINGLETONE_APPLICATION_H
#define SINGLETONE_APPLICATION_H

#include <SFML/Graphics.hpp>
#include <memory>
#include "GameObject.h"

//Класс синглтон, который дает возможность создать единственное окно, в котором будут происходить все действия и отрисовываться объекты
class Application {

    static Application* p_instance;
    sf::RenderWindow* window;
    std::vector<GameObject*> allObjects;
//    sf::RenderWindow windowID = *window;

    Application ();
    Application (const Application&);
    Application& operator= (Application&);

public:

    static Application* getInstance() {
        if(!p_instance)
            p_instance = new Application();
        return p_instance;
    }

    sf::RenderWindow* getWindow () {
        return window;
    }
};




#endif //SINGLETONE_APPLICATION_H
