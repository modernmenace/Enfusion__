#include "Player.h"

Player::Player(std::string spriteName, sf::Vector2f position)
{
    addComponent<Position>(position);
    addComponent<AnimatedSprite>(spriteName, 4, 3, sf::IntRect(0, 0, 180, 256));
    addComponent<Camera>(CameraType::FOLLOW, this);
    addComponent<AnimatedMovement>();
}