// Scene.cpp

#include "Scene.hpp"

Scene::Scene(int width, int height, Context& ctx) : m_width(width), m_height(height), context(ctx) {
    m_canvas.create(m_width, m_height);
}

void Scene::init() {
    for (auto& object : m_objects) {
        object.init();
    }
}

void Scene::setOrigin(int x, int y) {
    m_canvasSprite.setOrigin(x, y);
}

void Scene::setPosition(int x, int y) {
    m_canvasSprite.setPosition(x, y);
}

void Scene::update(float deltaTime) {
    for (auto& object : m_objects) {
        object.update(deltaTime);
    }

    checkCollisions();
}

void Scene::processInput(sf::Event& event) {
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2f clickPosition = context.window.mapPixelToCoords(sf::Mouse::getPosition(context.window));
            if (m_canvasSprite.getGlobalBounds().contains(clickPosition)) {
                sf::Vector2f localClickPosition = clickPosition - m_canvasSprite.getPosition();
                addObject(localClickPosition);
            }
        }
    }
}

void Scene::draw(sf::RenderTarget& display_canvas) {
    m_canvas.clear(m_bg_color);

    // Draw each object
    for (auto& object : m_objects) {
        object.draw(m_canvas);
    }

    m_canvas.display();
    m_canvasSprite.setTexture(m_canvas.getTexture());
    display_canvas.draw(m_canvasSprite);
}

void Scene::addObject(sf::Vector2f position) {
    Object newObject(position, 20.0f);
    newObject.setBounds(0, 0, m_width, m_height); // Set bounds for the new object
    m_objects.push_back(newObject);
}

void Scene::checkCollisions() {
    // Iterate over each object pair and check for collisions
    for (auto it1 = m_objects.begin(); it1 != m_objects.end(); ++it1) {
        for (auto it2 = std::next(it1); it2 != m_objects.end(); ++it2) {
            it1->processCollision(*it2);
        }
    }
}
