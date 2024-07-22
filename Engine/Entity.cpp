#include "Entity.hpp"

void Entity::draw(sf::RenderWindow* window) {

}

void Mesh::setShape(enum ShapeType type) {
    switch(type) {
        case ShapeType::Rectangle:
            shapeType = type;
            break;
        case ShapeType::Circle:
            shapeType = type;
            break;
        case ShapeType::None:
            shapeType = type;
        default:
            break;
    }
}

void Mesh::draw(sf::RenderWindow* window) {
    if(shapeType == ShapeType::Rectangle)
    {
        rectangleshape.setPosition(position);
        rectangleshape.setSize(size);
        window->draw(rectangleshape);
    }
    else if(shapeType == ShapeType::Circle) {
        circleshape.setPosition(position);
        circleshape.setRadius(radius);
        window->draw(circleshape);
    }
}
