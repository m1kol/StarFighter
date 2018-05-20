#include <SFML/Graphics/Texture.hpp>
#include "../headers/GameObject.h"


ComponentType::ComponentType() {}

ComponentType::~ComponentType() {}


RigidBody::RigidBody () {}

RigidBody::~RigidBody() {}


Collider::Collider() {}

Collider::~Collider() {}


Render::Render (std::string File, float X, float Y, float W, float H) {
    F = File;
    width = W; height = H;
    image.loadFromFile(F);
    texture.loadFromImage(image);
    sprite.setTexture(texture);
    x = X; y = Y;
    sprite.setTextureRect(sf::IntRect(0, 0, width, height));

    ComponentType::str = "Render";
}

Render::~Render() {}

void Render::draw () {}

GameObject::GameObject() {}

GameObject::~GameObject() {}

void GameObject::addComponent (ComponentType &component) {
    components.push_back(&component);
}

ComponentType *GameObject::getComponent(int a) {
    return components[a];
}
void GameObject::translate () {}

void GameObject::rotate () {}
