#include "Object.hpp"

Object::Object(sf::Vector2f startPosition, float mass)
    : position(startPosition), prevPosition(startPosition), velocity(0, 0), mass(mass) {
    shape.setRadius(mass);
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(position);
}

void Object::init() {
    // Initialization logic here
}

void Object::update(float deltaTime) {
    // Apply gravity
    const sf::Vector2f gravity(0, 9.8f); // Adjust gravity as needed
    sf::Vector2f gravitationalForce = gravity * mass * 0.9f;
    velocity += gravitationalForce * deltaTime;

    // Apply velocity to position
    position += velocity * deltaTime;

    if (position.x < bounds.left) {
        position.x = bounds.left;
        velocity.x = -velocity.x; // Reverse X velocity
    }
    else if (position.x > bounds.left + bounds.width) {
        position.x = bounds.left + bounds.width;
        velocity.x = -velocity.x; // Reverse X velocity
    }

    if (position.y < bounds.top) {
        position.y = bounds.top;
        velocity.y = -velocity.y; // Reverse Y velocity
    }
    else if (position.y > bounds.top + bounds.height) {
        position.y = bounds.top + bounds.height;
        velocity.y = -velocity.y; // Reverse Y velocity
    }

    // Update shape position
    shape.setPosition(position);
}

void Object::processInput() {
    // Input processing logic here
}

void Object::draw(sf::RenderTexture& display_canvas) {
    display_canvas.draw(shape);
}

void Object::setBounds(float left, float top, float width, float height) {
    bounds = sf::FloatRect(left, top, width, height);
}

const sf::CircleShape& Object::getShape() const {
    return shape;
}

sf::Vector2f Object::getPosition() const {
    return position;
}

sf::Vector2f Object::getVelocity() const {
    return velocity;
}

void Object::setPosition(sf::Vector2f newPosition) {
    position = newPosition;
}

void Object::setVelocity(sf::Vector2f newVelocity) {
    velocity = newVelocity;
}

void Object::integrate(float deltaTime) {
    // Verlet integration
    sf::Vector2f nextPosition = 2.f * position - prevPosition;
    prevPosition = position;
    position = nextPosition;
}

void Object::processCollision(Object& other) {
    // Custom collision handling logic here
    // For example, you can adjust velocities, apply forces, etc.
    // This function will be called when two objects collide
}
