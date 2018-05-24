#include <SFML/Graphics/Texture.hpp>
#include "../headers/GameObject.h"
#include <cmath>



ComponentType::ComponentType() {
}

ComponentType::~ComponentType() {}


Render::Render (std::string File, float X, float Y, float W, float H, int pos_x, int pos_y) {
    F = File;
    sf::IntRect rect(X, Y, W, H);
    width = W; height = H;
    x = X; y = Y;
    coord_x = pos_x;
    coord_y = pos_y;
    image.loadFromFile(F);
    texture.loadFromImage(image);
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(x, y, width, height));
    sprite.setPosition(coord_x, coord_y);

    ComponentType::str = "Render";
}

Render::~Render() {}


RigidBody::RigidBody (int Dx, int Dy) {
    dx = Dx;
    dy = Dy;
    ComponentType::str = "Rigid_Body";
}

RigidBody::~RigidBody() {}


Collider::Collider() {

    ComponentType::str = "Collider";
}

/*bool Collider::detectCollision(GameObject *Object, Application &app) {
    ComponentType *c = Object->getComponent("Render");
    Render *C = dynamic_cast<Render*>(c);
    GameObject *I;
    for (int i = 0; i < app.allObjects.size() ; i++) {
        I = app.allObjects[i];
        if(this->id == I->id ) {
           ComponentType* CT_I = I->getComponent("Render");
           Render *B = dynamic_cast<Render*>(CT_I);
            }
        }
    float a = abs(C->coord_x - B->coord_x );
    float b = abs(C->coord_y - B->coord_y );
    float sumw = (C->width + B->width)/2;
    float sumh = (C->height + B->height)/2;

//    std::cout << "B->coord_y: "<< B->coord_y<< "\n";

    if ((a <= sumw) or (b <= sumh))//если прямоугольники спрайтов пересекаются
         return true;
}*/

Collider::~Collider() {}

GameObject::GameObject(int ID) {
    id = ID;
}

GameObject::~GameObject() {}

void GameObject::addComponent (ComponentType &component) {
    components.push_back(&component);
    component.id = this->id;
}

ComponentType *GameObject::getComponent(std::string Type) {
    if (Type == "Render"){
        for (int i = 0; i < components.size() ; i++) {
            ComponentType *Object = components[i];
            if (Render *R_obj = dynamic_cast<Render *>(Object)) {
                return components[i];
            }

        }
    }
    else if(Type == "Collider") {
        for (int i = 0; i < components.size(); i++) {
            ComponentType *Object = components[i];
            if (Collider *C_obj = dynamic_cast<Collider *>(Object)) {
                return components[i];
            }
        }
    }
    else if(Type == "Rigid_Body") {
        for (int i = 0; i < components.size(); i++) {
            ComponentType *Object = components[i];
            if (RigidBody *RB_obj = dynamic_cast<RigidBody*>(Object)) {
                return components[i];
            }
        }
        }
    }


