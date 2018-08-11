#include "Player.h"

Player::Player(std::string spriteName, sf::Vector2f position) : GameObject(spriteName, position)
{

}

void Player::update()
{

}

void Player::handleInput(sf::Keyboard::Key key)
{
    auto x = sprite.getPosition().x;
    auto y = sprite.getPosition().y;

    switch (key)
    {
        case sf::Keyboard::W:
            //move up
            y -= speed;
            break;
        case sf::Keyboard::A:
            x -= speed;
            break;
        case sf::Keyboard::S:
            y += speed;
            break;
        case sf::Keyboard::D:
            x += speed;
            break;
        default:
            break;
    }
    sprite.setPosition(x, y);
}
