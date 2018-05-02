#include <SFML/Graphics/Texture.hpp>
#include "../headers/GameObject.h"


ComponentType::ComponentType() {}

ComponentType::~ComponentType() {}


RigidBody::RigidBody () {}

RigidBody::~RigidBody() {}


Collider::Collider() {}

Collider::~Collider() {}

Render::Render (std::string File, float X, float Y, float W, float H) {
    File = F;
    width = W; height = H;
    image.loadFromFile(File);
    image.createMaskFromColor(sf::Color(41, 33, 59));
    texture.loadFromImage(image);
    sprite.setTexture(texture);
    x = X; y = Y;
    sprite.setTextureRect(sf::IntRect(0, 0, width, height));
}

Render::~Render() {}

void Render::draw () {}

GameObject::GameObject() {}

GameObject::~GameObject() {}

void GameObject::addComponent (const ComponentType &component) {
    components.push_back(component);
}
void GameObject::translate () {}

void GameObject::rotate () {}
