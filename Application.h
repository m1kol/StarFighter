//
// Created by ann on 08.04.18.
//

#ifndef SINGLETONE_APPLICATION_H
#define SINGLETONE_APPLICATION_H
#include <iostream>
#include <SFML/Graphics.hpp>

//Класс синглтон, который дает возможность создать единственное окно, в котором будут происходить все действия и отрисовываться объекты
class Application

{
private:
    static Application * p_instance;
    sf::RenderWindow* window;
    Application();
    Application( const Application& );
    Application& operator=( Application& );
    sf::RenderWindow& windowID();
public:
    static Application * getInstance() {
        if(!p_instance)
            p_instance = new Application();
        return p_instance;
    }
};




#endif //SINGLETONE_APPLICATION_H
