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
    Render(std::string File, float X, float Y, float W, float H);
    ~Render();
    void draw();

private:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Image image;
    float x,y, height, width;
    std::string F;
};

class GameObject {
public:
    GameObject();
    ~GameObject();
    void addComponent(const ComponentType component);
    void translate();
    void rotate();

private:
    std::vector<int> coordinates[2];
    std::vector<ComponentType> components;
};

#endif
