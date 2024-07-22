#include <iostream>
#include <SFML/Graphics.hpp>
#include <Scene.hpp>
#include <Engine.hpp>
#include <Logic.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(800,600),"my window");
    window.setFramerateLimit(60);
    Engine engine(&window);
    Scene scene = LoadScene("./halo.json");
    engine.addSceneToGlobal(&scene);
    engine.switchMainScene("halo");
    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        window.clear();
        engine.update();
        window.display();
    }
    SaveScene("./halo.json",&scene);
    return 0;
}
