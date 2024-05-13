#include <SFML/Graphics.hpp>
#include "SceneHandler.h"
#include "EventHandler.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Shapes Example");

    SceneHandler sceneHandler;
    EventHandler eventHandler(window, sceneHandler);

    while (window.isOpen()) {
        window.clear();

        // Handle events (including adding shapes to the scene)
        eventHandler.handleEvents();

        // Draw all objects in the scene
        sceneHandler.drawObjects(window);

        window.display();
    }

    return 0;
}
