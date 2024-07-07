#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Entity.hpp"

class Scene {
    public:
        void init(const std::string& name);
        void createEntity(const std::string& entityName);
        void deleteEntity(const std::string& entityName);
        Entity* findEntity(const std::string& entityName);
    private:
        std::string SceneName;
        std::vector<Entity*> Entities;
};

