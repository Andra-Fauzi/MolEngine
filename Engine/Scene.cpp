#include "Scene.hpp"

std::string ShapeTypeToString(ShapeType shapeType) {
    switch (shapeType) {
        case ShapeType::Rectangle: return "rectangle";
        case ShapeType::Circle: return "circle";
        default: throw std::invalid_argument("Invalid ShapeType");
    }
}

ShapeType StringToShapeType(const std::string& str) {
    if (str == "rectangle") return ShapeType::Rectangle;
    if (str == "circle") return ShapeType::Circle;
    throw std::invalid_argument("Invalid string for ShapeType");
}

std::string EntityTypeToString(EntityType type) {
    switch (type) {
        case EntityType::Entity: return "entity";
        case EntityType::Mesh: return "mesh";
        default: throw std::invalid_argument("Invalid EntityType");
    }
}

EntityType StringToEntityType(const std::string& str) {
    if (str == "entity") return EntityType::Entity;
    if (str == "mesh") return EntityType::Mesh;
    throw std::invalid_argument("Invalid string for EntityType");
}

void Scene::insertEntity(std::shared_ptr<Entity> entity) {
    entity->ID = this->ID;
    this->ID++;
    entities.push_back(entity);
}

void Scene::insertEntity(std::shared_ptr<Mesh> mesh)
{
    mesh->ID = this->ID;
    this->ID++;
    meshes.push_back(mesh);
}

void Scene::drawEntity(sf::RenderWindow* window) {
    for(const std::shared_ptr<Mesh>& mesh : meshes)
    {
        mesh->draw(window);
    }
}

void Scene::fromJson(nlohmann::json& j)
{
    name = j["name"];
    for(const auto& entity : j["scene"])
    {
        if(entity.contains("shapetype"))
        {
            std::shared_ptr<Mesh> mesh = std::make_shared<Mesh>();
            mesh->name = entity.at("name").get<std::string>();
            mesh->rotation = entity.at("rotation").get<float>();
            mesh->ID = entity.at("ID").get<int>();
            mesh->position.x = entity.at("position.x").get<float>();
            mesh->position.y = entity.at("position.y").get<float>();
            mesh->size.x = entity.at("size.x").get<float>();
            mesh->size.y = entity.at("size.y").get<float>();
            mesh->shapeType = StringToShapeType(entity.at("shapetype").get<std::string>());
            mesh->type = StringToEntityType(entity.at("type").get<std::string>());
            insertEntity(mesh);
        }
    }
}

void Scene::toJson(nlohmann::json& j) {
    j["name"] = name;
    j["scene"] = nlohmann::json::array();
    for (const auto& entity : entities) {
        nlohmann::json js;
        js["rotation"] = entity->rotation;
        js["name"] = entity->name;
        js["ID"] = entity->ID;
        js["position.x"] = entity->position.x;
        js["position.y"] = entity->position.y;
        js["size.x"] = entity->size.x;
        js["size.y"] = entity->size.y;
        js["type"] = EntityTypeToString(entity->type);
        j["scene"].push_back(js);
    }
    for (const auto& mesh : meshes) {
        nlohmann::json js;
        js["rotation"] = mesh->rotation;
        js["name"] = mesh->name;
        js["ID"] = mesh->ID;
        js["position.x"] = mesh->position.x;
        js["position.y"] = mesh->position.y;
        js["size.x"] = mesh->size.x;
        js["size.y"] = mesh->size.y;
        js["shapetype"] = ShapeTypeToString(mesh->shapeType);
        js["type"] = EntityTypeToString(mesh->type);
        j["scene"].push_back(js);
    }
}
