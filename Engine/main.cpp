#include "main.hpp"

Engine::Engine(const char* title,sf::Vector2i resolution,bool Fullscreen) {
    win = new sf::RenderWindow(sf::VideoMode(resolution.x,resolution.y),title,(Fullscreen) ? sf::Style::Fullscreen : sf::Style::Default);
}

void Engine::update() {
    while(win->isOpen()) {
        sf::Event event;
        while(win->pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                win->close();
            }
        }
        win->clear(sf::Color::White);
        win->display();
    }
}

Engine::~Engine() {
    delete win;
}
