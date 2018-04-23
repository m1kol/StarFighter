#include "Application.h"

int main() {
    Application* instance = Application::getInstance();
    instance->getWindow();
    return 0;
}
