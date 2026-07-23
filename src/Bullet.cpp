#include <SFML/Graphics.hpp>
#include "../include/Bullet.hpp"

// Implement the constructor using the Bullet:: scope
Bullet::Bullet(sf::Vector2f position, sf::Vector2f direction) {
    shape.setSize({ 3.f, 8.f });
    shape.setFillColor(sf::Color::White);
    shape.setPosition(position);

    float speed = 5.f;
    velocity = direction * speed;
}

void Bullet::update(float dt) {
    shape.move(velocity * dt);
}

void Bullet::draw(sf::RenderWindow& window) {
    window.draw(shape);
}