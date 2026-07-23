#include <SFML/Graphics.hpp>
class Bullet {
    static constexpr float bulletWidth = 3.f; // Define bulletWidth as a static constant
public:
    sf::RectangleShape shape;
    sf::Vector2f velocity;
    Bullet(sf::Vector2f position, sf::Vector2f direction);
    bool isOffScreen() const;
    void update(float dt);
    void draw(sf::RenderWindow& window);
};