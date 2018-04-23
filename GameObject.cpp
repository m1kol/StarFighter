//
// Created by ann on 18.04.18.
//
#include "GameObject.h"

//векторы направления движения direction
std::vector<int> left(-1,0);
std::vector<int> right(1,0);
std::vector<int> up(0,1);
std::vector<int> down(0,-1);

//далее функция Translate будет усовершенствована, и движение будет происходить с какой-то скорость, а пока пусть так
void GameObject::Translate(std::vector<int> transform, std::vector<int> direction) {
    transform += direction;
}

void GameObject::Rotate() {}

void GameObject::addComponent(ComponentType * component) {
    Components.push_back(component);
}

Render::Render(sf::Texture _texture, sf::Sprite _sprite) {
    texture = _texture;
    sprite = _sprite;
}

RigidBody::RigidBody(float _mass, float _velocity_x, float _velocity_y, float _acceleration_x, float _acceleration_y) {
    mass =_mass;
    velocity_x = _velocity_x;
    velocity_y = _velocity_y;
    acceleration_x = _acceleration_x;
    acceleration_y = _acceleration_y;
}