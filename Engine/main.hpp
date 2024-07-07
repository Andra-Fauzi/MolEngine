#include <iostream>
#include <SFML/Graphics.hpp>

extern "C" {
    class Engine {
        public:
            Engine(const char* title,sf::Vector2i resolution,bool Fullscreen);
            void update();
            ~Engine();
            sf::RenderWindow* win;
    };
}

