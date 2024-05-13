#ifndef SHAPE_H
#define SHAPE_H

#include <SFML/Graphics.hpp>

class Shape {
public:
    virtual void draw(sf::RenderWindow& window) const = 0;
};

class Circle : public Shape {
public:
    Circle(float radius = 50.0f, sf::Vector2f position = sf::Vector2f(400.0f, 300.0f), sf::Color fillColor = sf::Color::Red);
    void draw(sf::RenderWindow& window) const override;

private:
    float m_radius;
    sf::Vector2f m_position;
    sf::Color m_fillColor;
};

class Square : public Shape {
public:
    Square(float sideLength = 100.0f, sf::Vector2f position = sf::Vector2f(400.0f, 300.0f), sf::Color fillColor = sf::Color::Blue);
    void draw(sf::RenderWindow& window) const override;

private:
    float m_sideLength;
    sf::Vector2f m_position;
    sf::Color m_fillColor;
};

class Triangle : public Shape {
public:
    Triangle(float sideLength = 100.0f, sf::Vector2f position = sf::Vector2f(400.0f, 300.0f), sf::Color fillColor = sf::Color::Green);
    void draw(sf::RenderWindow& window) const override;

private:
    float m_sideLength;
    sf::Vector2f m_position;
    sf::Color m_fillColor;
};

#endif // SHAPE_H
