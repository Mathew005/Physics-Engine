#include <SFML/Graphics.hpp>

class Circle {
public:
    Circle(float radius, sf::Vector2f position, sf::Color fillColor)
        : m_radius(radius), m_position(position), m_fillColor(fillColor) {}

    void draw(sf::RenderWindow& window) {
        sf::CircleShape circle(m_radius);
        circle.setPosition(m_position);
        circle.setFillColor(m_fillColor);
        window.draw(circle);
    }

private:
    float m_radius;
    sf::Vector2f m_position;
    sf::Color m_fillColor;
};

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Circle Example");

    // Create an instance of Circle with radius 50, position (400, 300), and red fill color
    Circle circle(50.0f, sf::Vector2f(400.0f, 300.0f), sf::Color::Red);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        // Draw the circle
        circle.draw(window);

        window.display();
    }

    return 0;
}
