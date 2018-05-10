#include "../headers/Application.h"


int main() {

    auto& s = Application::getInst();
//Создадим пробный объект - мяч, у которого отсутсвует компонента RigidBody
    GameObject Ball;
    Render Render_Ball("hero.png",250,250,96.0, 96.0);
    Ball.addComponent(Render_Ball);
    Collider Collider_Ball;
    Ball.addComponent(Collider_Ball);
    s.createObject(Ball);
    s.createRObject(Ball);
    s.run();


    std::vector<ComponentType> C;
    C = Ball.components;
    std::cout << C.size();


    std::vector<GameObject> G;
    G = s.allObjects;
    std::cout << G.size();

    std::vector<Render> R;
    R = s.RObjects;
    std::cout << R.size();
    fflush(0);

    return 0;
}
