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
    std::string str = "ComponentType";
    virtual std::string MakePolymorphism() {}; //это дерьмо я делаю, чтобы использовать dynamic_cast<>()
};

class GameObject {
public:
    GameObject();
    ~GameObject();
    std::vector<ComponentType*> components;


    void addComponent(ComponentType &component);
    ComponentType *getComponent(std::string Type);
    void translate();
    void rotate();

private:
    std::vector<int> coordinates[2];
//  std::vector<ComponentType> components;
};


class Render : public ComponentType {
public:
    Render(std::string File, float X, float Y, float W, float H, int pos_x, int pos_y);
    ~Render();

    std::string MakePolymorphism()
    {
        return "Renderer";
    };
    void draw();
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Image image;
    float x, y, width, height;
    int coord_x, coord_y;
    sf::IntRect rect;
    std::string F;

};

class RigidBody : public ComponentType {
public:
    RigidBody(int Dx, int Dy);
    ~RigidBody();
    std::string MakePolymorphism() {};
    int dx, dy;

};



class Collider : public ComponentType {
public:

    Collider();
    ~Collider();
    bool detectCollision(GameObject *Object);
    std::string MakePolymorphism() {};
    int a =1;
};






#endif
