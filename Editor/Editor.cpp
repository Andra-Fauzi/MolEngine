#include "Editor.hpp"

void Editor::init()
{
    run = true;
}

void Editor::Event(sf::Event& event)
{
    if(run == true)
    {
        ImGui::SFML::ProcessEvent(event);
    }
}

void Editor::Update(sf::RenderWindow* window)
{
    if(run == true)
    {
        ImGui::SFML::Update(*window,deltaclock.restart());
    }
}

void Editor::render(sf::RenderWindow* window)
{
    if(run == true)
    {
        ImGui::SFML::Render(*window);
    }
}

void Editor::DrawUI()
{
    if(run == true)
    {
    }
}
