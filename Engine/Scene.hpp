#pragma once
#include "Entity.hpp"
#include <iostream>
#include <memory>
#include <unordered_map>
#include <vector>
#include <nlohmann/json.hpp>

class Scene {
    public:
    void insertEntity(std::shared_ptr<Entity> entity);
    void insertEntity(std::shared_ptr<Mesh> mesh);
    void drawEntity(sf::RenderWindow* window);
    void fromJson(nlohmann::json& j);
    void toJson(nlohmann::json& j);
    std::vector<std::shared_ptr<Entity>> entities;
    std::vector<std::shared_ptr<Mesh>> meshes;
    std::string name = "main";
    int ID;
};
