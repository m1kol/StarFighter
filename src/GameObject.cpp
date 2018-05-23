#include <SFML/Graphics/Texture.hpp>
#include "../headers/GameObject.h"
#include <cmath>


ComponentType::ComponentType() {}

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

void Render::draw () {}


RigidBody::RigidBody (int Dx, int Dy) {
//    coord_x = Object->coord_x;
//    coord_y = Object->coord_y;
    dx = Dx;
    dy = Dy;
    ComponentType::str = "Rigid_Body";
}

RigidBody::~RigidBody() {}


Collider::Collider() {

    ComponentType::str = "Collider";
}
//здесь dynamic_cast() работает неправильно
bool Collider::detectCollision(GameObject *Object) {
    ComponentType *c = Object->getComponent("Render");
    Render *C = dynamic_cast<Render*>(c);
    std::cout << C->height<< "\n";
    ComponentType *A = dynamic_cast<ComponentType*> (this);
    std::cout << A->str<<"end" << "\n";
    Render *B = static_cast<Render*>(A);
    float a = abs(C->coord_x - B->coord_x );
    float b = abs(C->coord_y - B->coord_y );
    float sumw = (C->width + B->width)/2;
    float sumh = (C->height + B->height)/2;

//    std::cout << "B->coord_y: "<< B->coord_y<< "\n";

    if ((a <= sumw) or (b <= sumh))//если прямоугольники спрайтов пересекаются
         return true;
}

Collider::~Collider() {}

GameObject::GameObject() {}

GameObject::~GameObject() {}

void GameObject::addComponent (ComponentType &component) {
    components.push_back(&component);
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

void GameObject::translate () {}

void GameObject::rotate () {}
