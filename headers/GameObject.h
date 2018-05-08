#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <vector>
#include <iostream>
#include <SFML/Graphics/Sprite.hpp>

class ComponentType {
public:
    ComponentType();
    ~ComponentType();
    virtual std::string MakePolymorphism() {}; //это дерьмо я делаю, чтобы использовать dynamic_cast<>()
};


class RigidBody : public ComponentType {
public:

    RigidBody();
    ~RigidBody();
    std::string MakePolymorphism() {};

};



class Collider : public ComponentType {
public:

    Collider();
    ~Collider();
    std::string MakePolymorphism() {};
};


class Render : public ComponentType {
public:
    Render(std::string File, float X, float Y, float W, float H);
    ~Render();
    std::string MakePolymorphism() {};
    void draw();
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
    ComponentType getComponent(int a);
    void translate();
    void rotate();

private:
    std::vector<int> coordinates[2];
    std::vector<ComponentType> components;
};

#endif
