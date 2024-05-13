#include "Shape.h"

Circle::Circle(float radius, sf::Vector2f position, sf::Color fillColor)
    : m_radius(radius), m_position(position), m_fillColor(fillColor) {}

void Circle::draw(sf::RenderWindow& window) const {
    sf::CircleShape circle(m_radius);
    circle.setOrigin(m_radius, m_radius); // Set origin to center
    circle.setPosition(m_position);
    circle.setFillColor(m_fillColor);
    window.draw(circle);
}

Square::Square(float sideLength, sf::Vector2f position, sf::Color fillColor)
    : m_sideLength(sideLength), m_position(position), m_fillColor(fillColor) {}

void Square::draw(sf::RenderWindow& window) const {
    sf::RectangleShape square(sf::Vector2f(m_sideLength, m_sideLength));
    square.setOrigin(m_sideLength / 2, m_sideLength / 2); // Set origin to center
    square.setPosition(m_position);
    square.setFillColor(m_fillColor);
    window.draw(square);
}

Triangle::Triangle(float sideLength, sf::Vector2f position, sf::Color fillColor)
    : m_sideLength(sideLength), m_position(position), m_fillColor(fillColor) {}

void Triangle::draw(sf::RenderWindow& window) const {
    sf::ConvexShape triangle(3);
    triangle.setPoint(0, sf::Vector2f(0, -m_sideLength / 2));
    triangle.setPoint(1, sf::Vector2f(m_sideLength / 2, m_sideLength / 2));
    triangle.setPoint(2, sf::Vector2f(-m_sideLength / 2, m_sideLength / 2));
    triangle.setOrigin(0, -m_sideLength / 6); // Set origin to center
    triangle.setPosition(m_position);
    triangle.setFillColor(m_fillColor);
    window.draw(triangle);
}
