#include <SFML/Graphics.hpp>
#include <iostream>
#include "Scene.hpp"  // Include your header files properly

int main()
{
    Scene scene;
    scene.init("Main");

    // Create and manage entities
    scene.createEntity("patrick_star");

    // Find the entity
    Entity* patrick = scene.findEntity("patrick_star");
    if (patrick == nullptr) {
        std::cout << "patrick_star not found" << std::endl;
    } else {
        std::cout << "Found entity: " << patrick->name << std::endl;
    }

    // Delete the entity
    scene.deleteEntity("patrick_star");

    // Try to find the entity again
    patrick = scene.findEntity("patrick_star");
    if (patrick == nullptr) {
        std::cout << "patrick_star successfully deleted" << std::endl;
    }

    return EXIT_SUCCESS;
}
