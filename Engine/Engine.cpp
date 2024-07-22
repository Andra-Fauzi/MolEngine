#include "Engine.hpp"

std::vector<Scene*> GlobalScenes;

Engine::Engine(sf::RenderWindow* window)
{
    this->window = window;
}
void Engine::update()
{
    editor.Update(window);
    mainScene->drawEntity(window);
}

void Engine::switchMainScene(std::string nameScene) {
    for(Scene* scene : GlobalScenes)
    {
            if(scene->name == nameScene)
            {
                mainScene = scene;
                return;
            }
    }
    std::cout << "not found" << std::endl;
}

void Engine::addSceneToGlobal(Scene* scene)
{
    GlobalScenes.push_back(scene);
}
