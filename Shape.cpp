#include "Shape.h"

Circle::Circle(float radius, 
               float mass, 
               sf::Vector2f position, 
               sf::Color fillColor)
    : m_radius(radius), m_position(position), m_fillColor(fillColor), m_mass(mass) {}

void Circle::draw(sf::RenderWindow& window) const {
    sf::CircleShape circle(m_radius);
    circle.setOrigin(m_radius, m_radius); // Set origin to center
    circle.setPosition(m_position);
    circle.setFillColor(m_fillColor);
    window.draw(circle);
}

float Circle::getMass() const {
    return m_mass;
}

void Circle::applyForce(const sf::Vector2f& force) {
    // Implement applyForce method if needed
}

void Circle::update(float deltaTime) {
    // Implement update method if needed
}

