#include <SFML/Graphics.hpp>
#include "Scene.hpp"
#include <windows.h>

int main() {
    int WIN_WIDTH = 1920 / 2, WIN_HEIGHT = 1080 / 2;

    sf::RenderWindow window(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT), "SFML Window");
    Context context{ window };

    const sf::Time TIME_PER_FRAME = sf::seconds(1.f / 60.f);
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    sf::Time elapsed = sf::Time::Zero;
    unsigned int frames = 0;

    Scene scene1(WIN_WIDTH / 3, WIN_HEIGHT, context);
    scene1.setPosition(WIN_WIDTH / 3, 0);
    scene1.init();

    // Add initial objects to the scene
    Object obj(sf::Vector2f(100, 100), 5);
    obj.setBounds(0, 0, WIN_WIDTH / 3, WIN_HEIGHT); // Set bounds for the object
    scene1.m_objects.push_back(obj);

    while (window.isOpen()) {
        sf::Time deltaTime = clock.restart();
        timeSinceLastUpdate += deltaTime;
        elapsed += deltaTime;
        ++frames;

        float fps = frames / elapsed.asSeconds();
        window.setTitle("SFML Window - FPS: " + std::to_string(std::roundf(fps) ) );

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                HWND console = GetConsoleWindow();
                if (console != NULL) {
                    CloseWindow(console);
                }
            }
            if (event.type == sf::Event::KeyPressed) {
                switch (event.key.code)
                {
                case sf::Keyboard::Escape: {
                    window.close();
                    HWND console = GetConsoleWindow();
                    if (console != NULL) {
                        CloseWindow(console);
                    }
                    break;
                }
                default:
                    break;
                }
            }

            scene1.processInput(event);
        }

        while (timeSinceLastUpdate > TIME_PER_FRAME) {
            timeSinceLastUpdate -= TIME_PER_FRAME;

            scene1.update(TIME_PER_FRAME.asSeconds()); // Update the scene with the fixed time step

            window.clear();
            scene1.draw(window);
            window.display();
        }
    }

    return 0;
}
