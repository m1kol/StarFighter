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
