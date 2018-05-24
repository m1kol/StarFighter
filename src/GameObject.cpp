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


