//
// Created by ann on 18.04.18.
//

#ifndef CPP_MIPT_GAME_PROJECT_GAMEOBJECT_H
#define CPP_MIPT_GAME_PROJECT_GAMEOBJECT_H

#endif //CPP_MIPT_GAME_PROJECT_GAMEOBJECT_H
#include <vector>
#include <iostream>
#include <SFML/Graphics/Sprite.hpp>

class ComponentType {
    ComponentType();
    ~ComponentType();
};


class RigidBody : public ComponentType {
    RigidBody();
    ~RigidBody();
public:
    float mass, velocity_x, velocity_y, x, y, acceleration_x, acceleration_y;
};

class Collider : public ComponentType {
    Collider();
    ~Collider();
public:
    bool isCollision() {};
    void resolveCollision() {};
};

class Render : public ComponentType {
    Render();
    ~Render();
public:
    sf::Sprite sprite;
    void draw() {};
};

class GameObject {
public:
    std::vector<ComponentType*> Components;
    void addComponent(ComponentType* component) {
        Components.push_back(component);
    };
};