#include <SFML/Graphics.hpp>
#include "../include/Bullet.hpp"

// Implement the constructor using the Bullet:: scope

Bullet::Bullet(sf::Vector2f position, sf::Vector2f direction) {
    shape.setSize({ bulletWidth, 8.f });
    shape.setFillColor(sf::Color::Yellow);
    shape.setPosition(position);
    shape.setOrigin({ bulletWidth / 2.f, 4.f }); // Center the origin of the bullet shape

    float speed = 5.f;
    velocity = direction * speed;
}

void Bullet::update(float dt) {
    shape.move(velocity * dt);
}

void Bullet::draw(sf::RenderWindow& window) {
    window.draw(shape);
}