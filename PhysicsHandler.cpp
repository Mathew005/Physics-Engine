#include "PhysicsHandler.h"

PhysicsHandler::PhysicsHandler(float gravity) : m_gravity(gravity) {}

void PhysicsHandler::addObject(std::shared_ptr<Shape> shape) {
    m_objects.push_back(shape);
}

void PhysicsHandler::updatePhysics(float deltaTime) {
    // Apply gravity to each object
    for (const auto& object : m_objects) {
        // F = ma, so a = F/m
        sf::Vector2f gravityForce(0.0f, m_gravity * object->getMass());
        object->applyForce(gravityForce);

        // Update physics state of the object
        object->update(deltaTime);
    }
}
