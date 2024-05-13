#ifndef SCENE_HANDLER_H
#define SCENE_HANDLER_H

#include "Shape.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

class SceneHandler {
public:
    SceneHandler();
    void addObject(std::shared_ptr<Shape> shape);
    void drawObjects(sf::RenderWindow& window) const;

private:
    std::vector<std::shared_ptr<Shape>> m_objects;
};

#endif // SCENE_HANDLER_H
