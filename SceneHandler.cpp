#include "SceneHandler.h"

SceneHandler::SceneHandler() {}

void SceneHandler::addObject(std::shared_ptr<Shape> shape) {
    m_objects.push_back(shape);
}

void SceneHandler::drawObjects(sf::RenderWindow& window) const {
    for (const auto& object : m_objects) {
        object->draw(window);
    }
}
