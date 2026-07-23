#include <SFML/Graphics.hpp>
class Bullet {
public:
    sf::RectangleShape shape;
    sf::Vector2f velocity;
    Bullet(sf::Vector2f position, sf::Vector2f direction);
    void update(float dt);
    void draw(sf::RenderWindow& window);
};