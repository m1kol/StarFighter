//
// Created by ann on 08.04.18.
//

#include "Application.h"

Application::Application() {
    sf::RenderWindow Window(sf::VideoMode(200, 200), "Game");
    window = &Window;
}

sf::RenderWindow& Application::windowID() {
    return *window;
}

Application* Application::p_instance = 0;