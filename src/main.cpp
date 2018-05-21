#include "../headers/Application.h"
#include "../headers/wrap_creation.h"

int main() {

    auto& s = Application::getInst();
//Создадим пробный объект - мяч, у которого отсутсвует компонента RigidBody
    GameObject Ball;
    Render Render_Ball("hero.png",255,255,97.0, 97.0);
    Ball.addComponent(Render_Ball);
    Collider Collider_Ball(255,255,97.0, 97.0);
    Ball.addComponent(Collider_Ball);
    make_Render(&Ball, s);
    make_Collider(&Ball,s);
    GameObject Ball1;
    Render Render_Ball1("spaceship.png",250,250,96.0, 96.0);
    Ball1.addComponent(Render_Ball1);
    Collider Collider_Ball1(250,250,96.0, 96.0);
    Ball1.addComponent(Collider_Ball1);
    make_Render(&Ball1, s);
    make_Collider(&Ball1, s);

//    GameObject* Test;
//    Test = create_R_and_C_Object("hero.png",250,250,96.0, 96.0);
//    make_Render(Test, s);
    s.run();
    s.update();


    std::vector<ComponentType*> C;
    C = Ball.components;
    std::cout << C.size()<< "\n";


    std::vector<Render*> R;
    R = s.R_Objects;
    std::cout << R.size()<< "\n";
    fflush(0);

    return 0;
}
