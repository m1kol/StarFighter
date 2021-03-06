#include "../headers/Application.h"
#include "../headers/wrap_creation.h"

int main() {

    auto& app = Application::getInst();

    GameObject Background(1);
    Render Render_Background("spaceart.png",0,0,1600.0, 1066.0, 0, 0);
    Background.addComponent(Render_Background);
    make_Render(&Background, app);


    GameObject Hero(2);
    Render Render_Hero("hero.png",0,0,97.0, 97.0, 350, 350);
    Hero.addComponent(Render_Hero);
    Collider Collider_Hero;
    Hero.addComponent(Collider_Hero);
    make_Render(&Hero, app);
    make_Collider(&Hero,app);

    GameObject Star(3);
    Render Render_Star("star.png",0,0,80.0, 80.0, 0, 0);
    Star.addComponent(Render_Star);
    Collider Collider_Star;
    Star.addComponent(Collider_Star);
    RigidBody RigidBody_Star(7, 7);
    Star.addComponent(RigidBody_Star);
    make_Render(&Star, app);
    make_Collider(&Star,app);
    make_RigidBody(&Star, app);

    app.allObjects.push_back(&Background);
    app.allObjects.push_back(&Hero);
    app.allObjects.push_back(&Star);

    app.run();
//    std::cout << app.detectCollision(&Hero, &Star)<< "\n";
//    app.update();

    return 0;
}
