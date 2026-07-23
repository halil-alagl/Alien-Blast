#include <iostream>
#include <algorithm>
#include <SFML/Graphics.hpp>
#include "../include/Bullet.hpp"
int main() {
    float dt = 0.016f; // Assuming a fixed delta time of 0.016 seconds (60 FPS)
    sf::RenderWindow window(sf::VideoMode({ 640, 360 }), "Alien-Blast");
    sf::Texture texture("Media/player.png", false, sf::IntRect({ 0, 0 }, { 24, 21 }));
    sf::Sprite player(texture);
    player.setOrigin({ 12.f, 10.5f }); // Set the origin to the center of the sprite

    std::vector<Bullet> bullets;

    sf::Clock shootClock;
    sf::Time shootCooldown = sf::seconds(0.3f);

    player.setPosition({ 320.f, 180.f });

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        // 1. Accumulate directional input
        sf::Vector2f movement(0.f, 0.f);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) movement.x -= 1.f;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) movement.x += 1.f;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) movement.y -= 1.f;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) movement.y += 1.f;

        // 2. Move player (speed * delta time)
        float speed = 5.f;
        player.move(movement * speed * dt);

        // 3. Clamp position inside screen bounds (accounting for player size)

        sf::Vector2f pos = player.getPosition(); // Adjust for the origin being at the center

        pos.x = std::clamp(pos.x, 0.f, 652.f - 12.f);
        pos.y = std::clamp(pos.y, 0.f, 370.5f - 10.5f);

        player.setPosition(pos);


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
        {
            if (shootClock.getElapsedTime() >= shootCooldown) {
                sf::Vector2f direction(0.f, -1.f);
                sf::Vector2f spawnPos = player.getPosition();// Center the bullet horizontally
                bullets.emplace_back(spawnPos, direction);

                shootClock.restart(); // Reset the timer after firing
            }
        }
        window.clear();
        window.draw(player);
        // Remove bullets that are off-screen
        bullets.erase(
            std::remove_if(bullets.begin(), bullets.end(), [](const Bullet& bullet) {
                return bullet.isOffScreen();
                }),
            bullets.end()
        );
        for (auto& bullet : bullets) {
            bullet.update(0.016f);
            bullet.draw(window);
        }
        window.display();
    }
}