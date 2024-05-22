#pragma once

#include <SFML/Graphics.hpp>
#include "Object.hpp"
#include <list>

struct Context {
    sf::RenderWindow& window;
};

class Scene {
private:
    sf::RenderTexture m_canvas;
    int m_width, m_height;
    sf::Sprite m_canvasSprite;
    Context& context;

public:
    sf::Color m_bg_color = sf::Color(112, 112, 112);
    std::list<Object> m_objects;

    Scene(int width, int height, Context& ctx);

    void init();
    void setOrigin(int x, int y);
    void setPosition(int x, int y);
    void update(float deltaTime);
    void processInput(sf::Event& event);
    void draw(sf::RenderTarget& display_canvas);
    void addObject(sf::Vector2f position);
    void checkCollisions();
};
