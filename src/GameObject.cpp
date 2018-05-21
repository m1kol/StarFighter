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


RigidBody::RigidBody () {}

RigidBody::~RigidBody() {}


Collider::Collider(Render *Object) {
    sf::IntRect r1(Object->x, Object->y, Object->width, Object->height);
}

bool Collider::detectCollision(Render *Object) {
    if (r1.intersects(sf::IntRect(Object->x, Object->y, Object->width, Object->height)))//если прямоугольники спрайтов пересекаются
         return true;
}

Collider::~Collider() {}

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
