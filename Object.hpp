#pragma once

#include <SFML/Graphics.hpp>

class Object {
public:
    Object(sf::Vector2f startPosition, float mass);

    void init();
    void update(float deltaTime);
    void processInput();
    void draw(sf::RenderTexture& display_canvas);
    void setBounds(float left, float top, float width, float height);

    const sf::CircleShape& getShape() const;
    sf::Vector2f getPosition() const;
    sf::Vector2f getVelocity() const;

    void setPosition(sf::Vector2f position);
    void setVelocity(sf::Vector2f velocity);

    void processCollision(Object& other);

private:
    sf::Vector2f position;
    sf::Vector2f prevPosition;
    sf::Vector2f velocity;
    sf::CircleShape shape;
    sf::FloatRect bounds;
    float mass;

    void integrate(float deltaTime);
    void applyGravity(float deltaTime);
};
