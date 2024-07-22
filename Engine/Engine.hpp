#pragma once
#include <SFML/Graphics.hpp>
#include <Editor.hpp>
#include "Scene.hpp"

extern std::vector<Scene*> GlobalScenes;

class Engine {
    public:
    Engine(sf::RenderWindow* window);
    void switchMainScene(std::string nameScene);
    void addSceneToGlobal(Scene* scene);
    void event();
    void update();
    void initEditor();
    Editor editor;
    sf::RenderWindow* window;
    Scene* mainScene;
};
