#pragma once
#include "Scene.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include <string>
#include <typeinfo>
#include <vector>
#include <dirent.h>
#include <sys/types.h>
#include "Entity.hpp"
#include <nlohmann/json.hpp>


std::vector<std::string> getFilesInDirectory(const std::string& path);

void SaveScene(const std::string& path,Scene* scene);

Scene LoadScene(const std::string& path);

void insertScenetoScene(Scene& scene1, const Scene& scene2);

void switchEntity(std::shared_ptr<Entity>& entity1, std::shared_ptr<Entity>& entity2);

std::shared_ptr<Mesh> CreateMesh(const std::string& name, sf::Vector2f size = sf::Vector2f(100, 100), sf::Vector2f position = sf::Vector2f(0, 0), ShapeType shapeType = ShapeType::None);

std::shared_ptr<Mesh> CreateMesh(const std::string& name, float radius = 10, sf::Vector2f position = sf::Vector2f(0, 0), ShapeType shapeType = ShapeType::Circle);

std::string stringoftype(const Entity& e);

std::string stringoftype(const Mesh& m);

std::string stringofShapetype(const Mesh& m);
