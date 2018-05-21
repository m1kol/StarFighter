#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <vector>
#include <iostream>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Rect.hpp>

class ComponentType {
public:
    ComponentType();
    ~ComponentType();
    std::string str;
    virtual std::string MakePolymorphism() {}; //это дерьмо я делаю, чтобы использовать dynamic_cast<>()
    float x,y, width, height;
};

class GameObject {
public:
    GameObject();
    ~GameObject();
    std::vector<ComponentType*> components;

    void addComponent(ComponentType &component);
    ComponentType *getComponent(int a);
    void translate();
    void rotate();

private:
    std::vector<int> coordinates[2];
//  std::vector<ComponentType> components;
};


class RigidBody : public ComponentType {
public:

    RigidBody();
    ~RigidBody();
    std::string MakePolymorphism() {};

};



class Collider : public ComponentType {
public:

    Collider(float X, float Y, float W, float H);
    ~Collider();
    sf::IntRect r1;
    bool detectCollision(Collider* Object);
    std::string MakePolymorphism() {};
};


class Render : public ComponentType {
public:
    Render(std::string File, float X, float Y, float W, float H);
    ~Render();

    std::string MakePolymorphism()
    {
        return "Renderer";
    };
    void draw();
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Image image;
    std::string F;
};




#endif
