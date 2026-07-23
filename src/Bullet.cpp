#include <SFML/Graphics.hpp>
#include "Bullet.hpp"
class Bullet {
public:
    sf::RectangleShape shape;
    sf::Vector2f velocity;

    Bullet(sf::Vector2f position, sf::Vector2f direction) {
        shape.setSize({ 8.f, 8.f });
        shape.setFillColor(sf::Color::Yellow);
        shape.setPosition(position);

        float speed = 600.f;
        velocity = direction * speed;
    }

    void update(float dt) {
        shape.move(velocity * dt);
    }

    void draw(sf::RenderWindow& window) {
        window.draw(shape);
    }
};