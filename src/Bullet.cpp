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

bool Bullet::isOffScreen() const {
    sf::Vector2f pos = shape.getPosition();
    // Allow a slight margin (-10.f to 650.f / 370.f) so bullets despawn fully out of view
    return (pos.x < -10.f || pos.x > 650.f || pos.y < -10.f || pos.y > 370.f);
}

void Bullet::update(float dt) {
    shape.move(velocity * dt);
}

void Bullet::draw(sf::RenderWindow& window) {
    window.draw(shape);
}