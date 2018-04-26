#include <SFML/Graphics/Texture.hpp>
#include "GameObject.h"

//векторы направления движения direction
std::vector<int> left(-1,0);
std::vector<int> right(1,0);
std::vector<int> up(0,1);
std::vector<int> down(0,-1);

// далее функция Translate будет усовершенствована, и движение будет происходить с какой-то скорость, а пока пусть так
void GameObject::translate (std::vector<int> direction) {
//    coordinates += direction;
}

void GameObject::rotate () {}

// Добавление ссылки на константную компоненту к компонентам объекта
void GameObject::addComponent (const ComponentType &component) {
    components.push_back(component);
}

ComponentType::ComponentType() {}

ComponentType::~ComponentType() {}

Render::Render (sf::Texture _texture, sf::Sprite _sprite) {
    texture = _texture;
    sprite = _sprite;
}

RigidBody::RigidBody (float _velocity_x, float _velocity_y) {
    velocity_x = _velocity_x;
    velocity_y = _velocity_y;
}