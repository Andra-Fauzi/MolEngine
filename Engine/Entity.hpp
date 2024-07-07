#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>

class Entity {
    public:
    void init(const std::string& name);
    void setRotation(float deegres);
    void setPosition(float x,float y);
    void setScale(float x,int y);
    std::string name;
    float rotation;
    sf::Vector2f scale;
    sf::Vector2f position;
};

