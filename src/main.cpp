#include "../headers/Application.h"


int main() {
    auto& s = Application::getInst();
    sf::RenderWindow* ss = s.getWindow();
    return 0;
}
