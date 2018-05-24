#ifndef SINGLETONE_APPLICATION_H
#define SINGLETONE_APPLICATION_H

#include <SFML/Graphics.hpp>
#include <memory>
#include "GameObject.h"
#include <iostream>
#include <typeinfo>
#include <SFML/Graphics/Rect.hpp>
#include "logic.h"

using namespace sf;
//Класс синглтон, который дает возможность создать единственное окно, в котором будут происходить все действия и отрисовываться объекты
class Application {

private:
    RenderWindow* ptrwindow;
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

    std::vector<GameObject*> allObjects;
    std::vector<Render*>R_Objects;
    std::vector<Collider*>C_Objects;
    std::vector<RigidBody*>RB_Objects;
    RenderWindow* getWindow() {
        return Application::ptrwindow;
    }
    void  run();
    void update();
    bool detectCollision(GameObject *o_1, GameObject *o_2);
    float time;

};




#endif //SINGLETONE_APPLICATION_H
