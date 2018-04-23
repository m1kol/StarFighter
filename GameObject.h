//
// Created by ann on 18.04.18.
//

#include <vector>
#include <iostream>
#include <SFML/Graphics/Sprite.hpp>

class ComponentType {
    ComponentType();
    ~ComponentType();
};


class RigidBody : public ComponentType {
    RigidBody(float _mass, float _velocity_x, float _velocity_y, float _acceleration_x, float _acceleration_y );
    ~RigidBody();
public:
    float mass, velocity_x, velocity_y, acceleration_x, acceleration_y;
};

class Collider : public ComponentType {
    Collider();
    ~Collider();
public:
    bool isCollision() {};
    void resolveCollision() {};
};

class Render : public ComponentType {
    Render(sf::Texture _texture, sf::Sprite _sprite);
    ~Render();
public:
    sf::Texture texture;
    sf::Sprite sprite;
    void draw();
};

class GameObject {
public:
    std::vector<int> transform;
    std::vector<ComponentType*> Components;
    void addComponent(ComponentType* component);
    void Translate(std::vector<int> transform, std::vector<int> direction);
    void Rotate();
};
