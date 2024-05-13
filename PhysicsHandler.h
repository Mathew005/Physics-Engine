#ifndef PHYSICS_HANDLER_H
#define PHYSICS_HANDLER_H

#include "Shape.h"
#include <vector>
#include <memory>

class PhysicsHandler {
public:
    PhysicsHandler(float gravity = 9.81f); // Default gravity value is 9.81 m/s^2
    void addObject(std::shared_ptr<Shape> shape);
    void updatePhysics(float deltaTime);

private:
    float m_gravity; // Gravity acceleration in m/s^2
    std::vector<std::shared_ptr<Shape>> m_objects;
};

#endif // PHYSICS_HANDLER_H
