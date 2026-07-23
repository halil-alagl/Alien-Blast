#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode({ 640, 360 }), "Alien-Blast");
    //sf::RectangleShape player({ 30.f, 40.f });
    sf::Texture texture("player.png", false, sf::IntRect({ 0, 0 }, { 32, 32 })); // Throws sf::Exception if an error occurs  
    sf::Sprite player(texture);
    player.setPosition({ 320.f, 180.f });

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
            player.move({ -0.1f, 0.f });
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
            player.move({ 0.1f, 0.f });
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
            player.move({ 0.f, -0.1f });
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
            player.move({ 0.f, 0.1f });

        window.clear();
        window.draw(player);
        window.display();
    }
}