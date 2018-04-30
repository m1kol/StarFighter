#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <vector>
#include <iostream>
#include <SFML/Graphics/Sprite.hpp>

class ComponentType {
public:
    ComponentType();
    ~ComponentType();
};


class RigidBody : public ComponentType {
public:

    RigidBody(float _velocity_x, float _velocity_y);
    ~RigidBody();
    float mass, velocity_x, velocity_y, acceleration_x, acceleration_y;
};

class Collider : public ComponentType {
public:

    Collider();
    ~Collider();
    bool isCollision();
    void resolveCollision();
};

class Render : public ComponentType {
    sf::Texture texture;
    sf::Sprite sprite;

public:
    Render(sf::Texture _texture, sf::Sprite _sprite);
    ~Render();

    void draw();
};

class GameObject {

    std::vector<int> coordinates;
    std::vector<ComponentType> components;

public:

    void addComponent(const ComponentType& component);
    virtual void translate(std::vector<int> direction);
    void rotate();
};

#endif