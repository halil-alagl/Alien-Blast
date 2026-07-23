#include <SFML/Graphics.hpp>
#include "../include/Bullet.hpp"
int main() {
    sf::RenderWindow window(sf::VideoMode({ 640, 360 }), "Alien-Blast");
    sf::Texture texture("Media/player.png", false, sf::IntRect({ 0, 0 }, { 32, 32 }));
    sf::Sprite player(texture);

    std::vector<Bullet> bullets;

    sf::Clock shootClock;
    sf::Time shootCooldown = sf::seconds(0.5f);

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


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
        {
            if (shootClock.getElapsedTime() >= shootCooldown) {
                sf::Vector2f direction(0.f, -1.f);
                bullets.emplace_back(player.getPosition(), direction);

                shootClock.restart(); // Reset the timer after firing
            }
        }
        window.clear();
        window.draw(player);

        for (auto& bullet : bullets) {
            bullet.update(0.016f);
            bullet.draw(window);
        }

        window.display();
    }
}