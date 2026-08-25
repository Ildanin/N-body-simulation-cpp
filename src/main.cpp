#include <SFML/Graphics.hpp>
#include "Star.hpp"
#include "Cluster.hpp"
#include "Parameters.hpp"
#include "Coords.hpp"
#include "Example.hpp"

int main() {
    srand(time(0));
    
    sf::RenderWindow window(sf::VideoMode({Param::WIDTH, Param::HEIGHT}), "N-body simulation");
    //window.setFramerateLimit(10000);

    //Cluster cluster = preset1(20, 500, 400, 100);
    Cluster cluster = preset2(400, 500, 100, 9000, 10, 10);

    sf::Font font;
    if (!font.openFromFile("assets/fonts/light-arial.ttf"))
        return 1;

    sf::Text fpsText(font);
    fpsText.setCharacterSize(24);
    fpsText.setFillColor(sf::Color::White);
    fpsText.setPosition({10.f, 10.f});

    sf::Clock clock;
    sf::Clock fpsClock;
    float dt;    

    while (window.isOpen()) {

        dt = clock.restart().asSeconds();
        if (fpsClock.getElapsedTime().asSeconds() >= 0.5f) {
            fpsText.setString("FPS: " + std::to_string(int(1.f / dt)));
            fpsClock.restart();
        }

        while (const std::optional event = window.pollEvent()) {
            if (event -> is<sf::Event::Closed>())
                window.close();
            if (const auto* wheel = event -> getIf<sf::Event::MouseWheelScrolled>()) {
                if (wheel -> delta > 0) zoomIn(dt);
                else zoomOut(dt);
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Up)) moveUp(dt);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Down)) moveDown(dt);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Right)) moveRight(dt);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Left)) moveLeft(dt);

        window.clear();

        cluster.update(dt);
        cluster.draw(window);

        window.draw(fpsText);
        window.display();
    }
}