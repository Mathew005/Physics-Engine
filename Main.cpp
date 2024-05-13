#include <SFML/Graphics.hpp>
#include <vector>

class Circle {
public:
    Circle(float radius = 50.0f, sf::Vector2f position = sf::Vector2f(400.0f, 300.0f), sf::Color fillColor = sf::Color::Red)
        : m_radius(radius), m_position(position), m_fillColor(fillColor) {}

    void draw(sf::RenderWindow& window) const {
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

class CircleGenerator {
public:
    CircleGenerator() = default;

    Circle generate(float radius = 30.0f, sf::Vector2f position = sf::Vector2f(0.0f, 0.0f), sf::Color fillColor = sf::Color::Green) const {
        return Circle(radius, position, fillColor);
    }
};

class EventHandler {
public:
    EventHandler(sf::RenderWindow& window, CircleGenerator& circleGenerator)
        : m_window(window), m_circleGenerator(circleGenerator) {}

    void handleEvents(std::vector<Circle>& circles) {
        sf::Event event;
        while (m_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                m_window.close();
            else if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    // Get the mouse position relative to the window
                    sf::Vector2f mousePosition = m_window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
                    // Generate a circle at the mouse position and store it
                    circles.push_back(m_circleGenerator.generate(30.0f, mousePosition, sf::Color::Green));
                }
            }
        }
    }

private:
    sf::RenderWindow& m_window;
    CircleGenerator& m_circleGenerator;
};

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Circle Example");

    CircleGenerator circleGenerator;
    EventHandler eventHandler(window, circleGenerator);

    std::vector<Circle> circles; // Store the circles that have been spawned

    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    sf::Time timePerFrame = sf::seconds(1.f / 60.f); // 60 frames per second

    while (window.isOpen()) {
        sf::Time elapsedTime = clock.restart();
        timeSinceLastUpdate += elapsedTime;

        // Handle events (including mouse clicks to spawn circles)
        eventHandler.handleEvents(circles);

        // Update at fixed time intervals
        while (timeSinceLastUpdate > timePerFrame) {
            timeSinceLastUpdate -= timePerFrame;
        }

        window.clear();

        // Draw the original red circle
        Circle originalCircle;
        originalCircle.draw(window);

        // Draw all spawned circles
        for (const auto& circle : circles) {
            circle.draw(window);
        }

        window.display();

        // Sleep to limit CPU usage
        sf::sleep(sf::milliseconds(1));
    }

    return 0;
}
