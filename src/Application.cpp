#include "../headers/Application.h"
#include <SFML/Window.hpp>
using namespace sf;


Application::Application() {
    ptrwindow = new RenderWindow(VideoMode(700, 700), "Game");
}

void  Application::run() {
    //движение объектов, у которых имеется компонента Rigid_Body
    for (int j = 0; j < RB_Objects.size(); j++) {
        int ID = RB_Objects[j]->id;
        GameObject *I;
        for (int i = 0; i < this->allObjects.size() ; i++) {
            I = this->allObjects[i];
            if(ID == I->id ) {
                ComponentType* CT_I = I->getComponent("Render");
                Render *R_I = dynamic_cast<Render*>(CT_I);
                int x= 355;
                int y = 340;
                R_I->sprite.move(x, y);
                R_I->coord_x = x;
                R_I->coord_y = y;
//                R_I->sprite.move((RB_Objects[j]->dx) * time*100, (RB_Objects[j]->dy) * time);

            }
        }
    }


    while (ptrwindow->isOpen()) {
            Clock clock;
            time = clock.getElapsedTime().asMicroseconds(); //дать прошедшее время в микросекундах
            clock.restart(); //перезагружает время
            time = time / 100; //скорость игры
            Event event;
            float CurrentFrame;

            while (ptrwindow->pollEvent(event)) {
                if (event.type == Event::Closed)
                    ptrwindow->close();
            }

            //выполняем логику для 1-го объекта
            Render *a = R_Objects[1];
            DIFFICULTANIMATION(a->sprite)

            ptrwindow->clear();
            for (int i = 0; i < R_Objects.size(); i++) {
                ptrwindow->draw(R_Objects[i]->sprite);
            }
            ptrwindow->display();
        }

    }

bool Application::detectCollision(GameObject *o_1, GameObject *o_2) {
    ComponentType *c = o_1->getComponent("Render");
    Render *C = dynamic_cast<Render*>(c);
    ComponentType *b = o_2->getComponent("Render");
    Render *B = dynamic_cast<Render*>(b);
    float aa = abs(C->coord_x - B->coord_x );
    float bb = abs(C->coord_y - B->coord_y );
    float sumw = (C->width + B->width)/2;
    float sumh = (C->height + B->height)/2;
    if ((aa <= sumw) and (bb <= sumh))//если прямоугольники спрайтов пересекаются
    return true;
            }



void Application::update() {
    int a = allObjects.size();
    for (int i = 0; i < a; i++) {
        for (int k = 0; k < a; k++) {
            if(i!=k){
                ComponentType *c = allObjects[i]->getComponent("Collider");
                ComponentType *b = allObjects[i]->getComponent("Collider");
                Collider *C = dynamic_cast<Collider*>(c);
                Collider *B = dynamic_cast<Collider*>(b);
                if((C) and (B)) {
                    if (this->detectCollision(allObjects[i], allObjects[k])){
                        std::cout << "Collision" << "\n";
                    }
                }
            }
        }
    }
}

Application::~Application() {
    delete ptrwindow;
}

