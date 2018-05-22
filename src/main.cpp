#include "../headers/Application.h"
#include "../headers/wrap_creation.h"

int main() {

    auto& s = Application::getInst();
//Первый пробный объект
    GameObject Ball;
    Render Render_Ball("hero.png",0,0,97.0, 97.0);
    Ball.addComponent(Render_Ball);
    Collider Collider_Ball(&Render_Ball);
    Ball.addComponent(Collider_Ball);
    Render *a = make_Render(&Ball, s);
    std::cout << a->height<<"\n";
    make_Collider(&Ball,s);
//Второй пробный объект
    GameObject Ball1;
    Render Render_Ball1("spaceship.png",0,0,96.0, 96.0);
    Ball1.addComponent(Render_Ball1);
    Collider Collider_Ball1(&Render_Ball1);
    Ball1.addComponent(Collider_Ball1);
    make_Render(&Ball1, s);
    make_Collider(&Ball1, s);


    ComponentType *R_Ball = Ball.getComponent("Render");
    std::cout  << R_Ball->str<<"\n";
    ComponentType *C_Ball = Ball.getComponent("Collider");
    std::cout << C_Ball->str<<"\n";

    s.allObjects.push_back(&Ball);
    s.allObjects.push_back(&Ball1);

//    GameObject* Test;
//    Test = create_R_and_C_Object("hero.png",250,250,96.0, 96.0);
//    make_Render(Test, s);
    s.run();
    s.update();
    std::cout << Collider_Ball.detectCollision(&Ball1)<< "\n";

//
//    std::vector<ComponentType*> C;
//    C = Ball.components;
//    std::cout << C.size()<< "\n";
//
//
    std::vector<Render*> R;
    R = s.R_Objects;
    std::cout << R.size()<< "\n";
    fflush(0);

    return 0;
}
