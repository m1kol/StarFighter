#include "../headers/Application.h"


int main() {

    auto& s = Application::getInst();
    sf::RenderWindow* ss = s.getWindow();
//Создадим пробный объект - мяч, у которого отсутсвует компонента RigidBody
    GameObject Ball;
    const Render Render_Ball("hero.png",250,250,96.0, 96.0);
    Ball.addComponent(Render_Ball);
    const Collider Collider_Ball;
    Ball.addComponent(Collider_Ball);
    s.createObject(Ball);
    s.createRObject(Ball);
    return 0;
}
