#include <iostream>
#include <SFML/Graphics.hpp>
#include "Application.h"
#include "GameObject.h"
#include "Application.cpp"
#include "GameObject.cpp"


int main() {
    Application * instance;
    instance->getInstance();
    return 0;
}
