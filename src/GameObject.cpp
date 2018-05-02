#include <SFML/Graphics/Texture.hpp>
#include "../headers/GameObject.h"


ComponentType::ComponentType() {}

ComponentType::~ComponentType() {}


RigidBody::RigidBody () {}

RigidBody::~RigidBody() {}


Collider::Collider() {}

Collider::~Collider() {}

Render::Render () {}

Render::~Render() {}

void Render::draw () {}


GameObject::GameObject() {}

GameObject::~GameObject() {}

void GameObject::addComponent (const ComponentType &component) {
    components.push_back(component);
}
void GameObject::translate () {}

void GameObject::rotate () {}
