#include "Application.h"
void mainloop() {
    while (window) {
        std::cout<<"Отрисовочка";
    }
}

Application::Application() {
    sf::RenderWindow Window(sf::VideoMode(200, 200), "Game");
    window = &Window;
    mainloop();
}

sf::RenderWindow& Application::windowID() {
    return *window;
}

Application* Application::p_instance = 0;
