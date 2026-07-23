#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "Star Chaser");
    sf::RectangleShape player({ 30.f, 40.f });
    player.setPosition({ 400.f, 300.f });

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
            player.move({ -0.1f, 0.f });
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
            player.move({ 0.1f, 0.f });

        window.clear();
        window.draw(player);
        window.display();
    }
}