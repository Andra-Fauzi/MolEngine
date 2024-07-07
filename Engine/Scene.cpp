
#include "Scene.hpp"
#include <algorithm>

void Scene::init(const std::string& name) {
    SceneName = name;
}

void Scene::createEntity(const std::string& entityName) {
    Entity* entity = new Entity();
    entity->init(entityName);
    Entities.push_back(entity);
    std::cout << "entity created name:" << entity->name << std::endl;
}

void Scene::deleteEntity(const std::string& entityName) {
    for (auto it = Entities.begin(); it != Entities.end(); ) {
        if ((*it)->name == entityName) {
            delete *it;  // Free the memory
            it = Entities.erase(it);  // Erase and update the iterator
        } else {
            ++it;  // Move to the next element
        }
    }
}

Entity* Scene::findEntity(const std::string& entityName) {
    for (auto entity : Entities) {
        if (entity->name == entityName) {
            return entity;
        }
    }
    return nullptr;
}
