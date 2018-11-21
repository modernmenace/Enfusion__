#include "Player.h"

Player::Player(std::string spriteName, sf::Vector2f position)
{
    // TODO: Many of these components (Animator / Input) require
    // TODO: other components to be set up first, add asserts or something
    // TODO: to make this safer
    addComponent<Position>(position);
    addComponent<AnimatedSprite>(spriteName, 4, 3, sf::IntRect(0, 0, 180, 256));
    //addComponent<Sprite>(spriteName);
    //addComponent<PlayerFreeInput>(150);
}