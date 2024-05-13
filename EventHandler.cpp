#include "EventHandler.h"

EventHandler::EventHandler(sf::RenderWindow& window, SceneHandler& sceneHandler)
    : m_window(window), m_sceneHandler(sceneHandler) {}

void EventHandler::handleEvents() {
    sf::Event event;
    while (m_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            m_window.close();
        else if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                // Get the mouse position relative to the window
                sf::Vector2f mousePosition = m_window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
                // Create a shape (circle, square, or triangle) and add it to the scene
                std::shared_ptr<Shape> shape;
                switch (m_shapeType) {
                case ShapeType::Circle:
                    shape = std::make_shared<Circle>(30.0f, mousePosition, sf::Color::Red);
                    break;
                case ShapeType::Square:
                    shape = std::make_shared<Square>(60.0f, mousePosition, sf::Color::Blue);
                    break;
                case ShapeType::Triangle:
                    shape = std::make_shared<Triangle>(60.0f, mousePosition, sf::Color::Green);
                    break;
                }
                m_sceneHandler.addObject(shape);
            }
        }
        else if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::C) {
                m_shapeType = ShapeType::Circle;
            }
            else if (event.key.code == sf::Keyboard::S) {
                m_shapeType = ShapeType::Square;
            }
            else if (event.key.code == sf::Keyboard::T) {
                m_shapeType = ShapeType::Triangle;
            }
        }
    }
}
