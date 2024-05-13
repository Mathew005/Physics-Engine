#include <SFML/Graphics.hpp>

class CircleSpawner {
public:
    CircleSpawner(sf::RenderWindow& window)
        : m_window(window) {}

    void handleEvents() {
        sf::Event event;
        while (m_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                m_window.close();
            else if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    // Spawn a circle at the mouse position
                    sf::CircleShape circle(20.0f);
                    circle.setFillColor(sf::Color::Green);
                    circle.setPosition(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y));
                    m_circles.push_back(circle);
                }
            }
        }
    }

    void drawCircles() {
        for (const auto& circle : m_circles) {
            m_window.draw(circle);
        }
    }

private:
    sf::RenderWindow& m_window;
    std::vector<sf::CircleShape> m_circles;
};

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Circle Spawner");

    CircleSpawner spawner(window);

    while (window.isOpen()) {
        window.clear();

        // Handle events (including mouse clicks to spawn circles)
        spawner.handleEvents();

        // Draw all spawned circles
        spawner.drawCircles();

        window.display();
    }

    return 0;
}
