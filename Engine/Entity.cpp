#include "Entity.hpp"

void Entity::init(const std::string& name) {
    this->name = name;
}

void Entity::setRotation(float deegres) {
    rotation = deegres;
}

void Entity::setPosition(float x,float y) {
    position.x = x;
    position.y = y;
}

void Entity::setScale(float x,int y) {
    scale.x = x;
    scale.y = y;
}

