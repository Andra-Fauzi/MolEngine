#include "Logic.hpp"

std::vector<std::string> getFilesInDirectory(const std::string& path) {
    std::vector<std::string> files;
    DIR* dirp = opendir(path.c_str());
    struct dirent* dp;
    while ((dp = readdir(dirp)) != nullptr) {
        if (dp->d_type == DT_REG) {
            files.push_back(dp->d_name);
        }
    }
    closedir(dirp);
    return files;
}

void insertScenetoScene(Scene& scene1, const Scene& scene2) {
    for (const auto& entity : scene2.entities) {
        scene1.insertEntity(entity);
    }
}

void switchEntity(std::shared_ptr<Entity>& entity1, std::shared_ptr<Entity>& entity2) {
    std::shared_ptr<Entity> temp = entity1;
    entity1 = entity2;
    entity2 = temp;
}

std::shared_ptr<Mesh> CreateMesh(const std::string& name, sf::Vector2f size, sf::Vector2f position, ShapeType shapeType) {
    auto mesh = std::make_shared<Mesh>();
    mesh->name = name;
    mesh->position = position;
    mesh->size = size;
    mesh->setShape(shapeType);
    return mesh;
}

std::shared_ptr<Mesh> CreateMesh(const std::string& name, float radius, sf::Vector2f position, ShapeType shapeType) {
    auto mesh = std::make_shared<Mesh>();
    mesh->name = name;
    mesh->position = position;
    mesh->radius = radius;
    mesh->setShape(shapeType);
    return mesh;
}

std::string stringoftype(const Entity& e)
{
    return "entity";
}

std::string stringoftype(const Mesh& m)
{
    return "mesh";
}

std::string stringofShapetype(const Mesh& m)
{
    switch(m.shapeType)
    {
        case ShapeType::Rectangle:
            return "rectangle";
            break;
        case ShapeType::Circle:
            return "cirlce";
            break;
        case ShapeType::None:
            return "none";
            break;
    }
    return "unknown";
}

Scene LoadScene(const std::string& path)
{

    nlohmann::json j;
    std::ifstream File(path);
    if(!File)
    {
        std::cerr << "cant read File" << std::endl;
    }
    File >> j;
    Scene scene;
    scene.fromJson(j);
    File.close();
    return scene;
}

void SaveScene(const std::string& path,Scene* scene)
{
    nlohmann::json j;
    std::ofstream File(path);
    scene->toJson(j);
    if(File.is_open())
    {
        File << j.dump(4);
        File.close();
    }
    else{
        std::cerr << "cant open File" << std::endl;
    }
}
