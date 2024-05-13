#ifndef SHAPE_H
#define SHAPE_H

#include <SFML/Graphics.hpp>
class Shape {
public:
    virtual void draw(sf::RenderWindow& window) const = 0;
    virtual float getMass() const = 0; // Add method to get mass
    virtual void applyForce(const sf::Vector2f& force) = 0; // Add method to apply force
    virtual void update(float deltaTime) = 0; // Add method to update physics state
};

class Circle : public Shape {
public:
    Circle(float radius = 50.0f, float mass = 1.0f, sf::Vector2f position = sf::Vector2f(400.0f, 300.0f), sf::Color fillColor = sf::Color::Red);
    void draw(sf::RenderWindow& window) const override;
    float getMass() const override;
    void applyForce(const sf::Vector2f& force) override;
    void update(float deltaTime) override;

private:
    float m_radius;
    sf::Vector2f m_position;
    sf::Color m_fillColor;
    float m_mass;
};

#endif // SHAPE_H
