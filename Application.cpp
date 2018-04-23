#include "Application.h"
#include "mainloop.cpp"

Application::Application() {
    sf::RenderWindow Window(sf::VideoMode(200, 200), "Game");
    window = &Window;
    //создаем массив из геймобджектов AllObjects, mainloop() нужно пройтись по всем созданным объектам, проверить
    // их на наличие компоненты Render и при обнаружении запустить функцию draw()
    GameObject *AllObjects = new GameObject[size];
    delete [] AllObjects;
    mainloop();
}

Application* Application::p_instance = 0;
