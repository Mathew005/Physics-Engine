#ifndef EVENT_HANDLER_H
#define EVENT_HANDLER_H

#include "SceneHandler.h"
#include <SFML/Graphics.hpp>

class EventHandler {
public:
    EventHandler(sf::RenderWindow& window, SceneHandler& sceneHandler);
    void handleEvents();

private:
    enum class ShapeType { Circle, Square, Triangle };
    sf::RenderWindow& m_window;
    SceneHandler& m_sceneHandler;
    ShapeType m_shapeType = ShapeType::Circle; // Default shape type
};

#endif // EVENT_HANDLER_H
