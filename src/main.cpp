#include "../headers/Application.h"
#include "../headers/wrap_creation.h"

int main() {

    auto& app = Application::getInst();

    GameObject Background;
    Render Render_Background("spaceart.png",0,0,1600.0, 1066.0, 0, 0);
    Background.addComponent(Render_Background);
    make_Render(&Background, app);


    GameObject Hero;
    Render Render_Hero("hero.png",0,0,97.0, 97.0, 350, 350);
    Hero.addComponent(Render_Hero);
    Collider Collider_Hero;
    Hero.addComponent(Collider_Hero);
    make_Render(&Hero, app);
    make_Collider(&Hero,app);


    app.allObjects.push_back(&Background);
    app.allObjects.push_back(&Hero);
//    for (int i = 0; i <Ball.components.size() ; i++) {
//        std::cout << Ball.components[i]->str << "\n";
//        std::cout << Ball.components[0]->height <<"\n";
//    }

    app.run();
//    s.update();

//    std::cout << Collider_Ball.detectCollision(&Ball1)<< "\n";

//
//    std::vector<ComponentType*> C;
//    C = Ball.components;
//    std::cout << C.size()<< "\n";
//
//
//    for (int i = 0; i <Ball.components.size() ; i++) {
//        std::cout << Ball.components[i]->str << "\n";
//    }
//
//    std::vector<Render*> R;
//    R = s.R_Objects;
//    std::cout << R.size()<< "\n";
//    fflush(0);

    return 0;
}
