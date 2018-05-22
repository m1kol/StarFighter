#include <SFML/Graphics/Texture.hpp>
#include "../headers/GameObject.h"


ComponentType::ComponentType() {}

ComponentType::~ComponentType() {}


Render::Render (std::string File, float X, float Y, float W, float H) {
    F = File;
    sf::IntRect rect(X, Y, W, H);
    width = W; height = H;
    image.loadFromFile(F);
    texture.loadFromImage(image);
    sprite.setTexture(texture);
    x = X; y = Y;
    sprite.setTextureRect(sf::IntRect(x, y, width, height));

    ComponentType::str = "Render";
}

Render::~Render() {}

void Render::draw () {}


RigidBody::RigidBody () {
    ComponentType::str = "Rigid_Body";
}

RigidBody::~RigidBody() {}


Collider::Collider(Render *Object) {
    sf::IntRect r1(Object->x, Object->y, Object->width, Object->height);
    ComponentType::str = "Collider";
}

bool Collider::detectCollision(GameObject *Object) {
    ComponentType *c = Object->getComponent("Render");
    Render *C = dynamic_cast<Render*>(c);
    if (r1.intersects(sf::IntRect(C->x, C->y, C->width, C->height)))//если прямоугольники спрайтов пересекаются
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
