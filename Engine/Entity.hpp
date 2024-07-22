#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <functional>

extern "C" {

enum class EntityType {
    Entity,
    Mesh
};

class Entity {
    public:
    virtual ~Entity() = default;
    virtual void draw(sf::RenderWindow* window);
    float rotation;
    std::string name;
    sf::Vector2f size;
    sf::Vector2f position;
    int ID;
    std::function<void()> update;
    EntityType type = EntityType::Entity;
};

enum class ShapeType {
    Rectangle,
    Circle,
    None
};

class Mesh : public Entity {
    public:
    void draw(sf::RenderWindow* window) override;
    void setShape(enum ShapeType type);
    sf::RectangleShape rectangleshape;
    sf::CircleShape circleshape;
    float radius;
    ShapeType shapeType;
    EntityType type = EntityType::Mesh;
};
}
