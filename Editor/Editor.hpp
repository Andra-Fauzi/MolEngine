#pragma once
#include <Engine.hpp>
#include "Imgui/imgui.h"
#include "Imgui/imgui-SFML.h"

class Editor
{
    public:
        void init();
        void EditorOn();
        void EditorOff();
        void Event(sf::Event& event);
        void Update(sf::RenderWindow* window);
        void DrawUI();
        void render(sf::RenderWindow* window);
        bool run;
        sf::Clock deltaclock;
};
