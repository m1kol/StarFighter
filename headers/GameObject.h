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

    RigidBody();
    ~RigidBody();

};


class Collider : public ComponentType {
public:

    Collider();
    ~Collider();

};


class Render : public ComponentType {
public:
    Render();
    ~Render();
    void draw();
};

class GameObject {
public:
    GameObject();
    ~GameObject();
    void addComponent(const ComponentType& component);
    void translate();
    void rotate();

private:
    std::vector<int> coordinates[2];
    std::vector<ComponentType> components;
};

#endif
