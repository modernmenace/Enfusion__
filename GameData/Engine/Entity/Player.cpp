#include "Player.h"

Player::Player(std::string spriteName, sf::Vector2f position)
{

    addComponent<Position>(position);
    addComponent<Sprite>(spriteName);
    addComponent<PlayerFreeInput>();
}