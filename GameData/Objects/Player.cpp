#include "Player.h"

Player::Player(std::string spriteName, sf::Vector2f position) : GameObject(spriteName, position)
{

}

void Player::update()
{

}

void Player::handleInput(sf::Keyboard::Key key) {
    // check for diagonals
    // probe with isKeyPressed

    if (key == sf::Keyboard::W)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            sprite.move(-speed, -speed);
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            sprite.move(speed, -speed);
        else
            sprite.move(0, -speed);
    }
    else if (key == sf::Keyboard::A)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            sprite.move(-speed, -speed);
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            sprite.move(-speed, speed);
        else
            sprite.move(-speed, 0);
    }
    else if (key == sf::Keyboard::S)
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            sprite.move(-speed, speed);
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            sprite.move(speed, speed);
        else
            sprite.move(0, speed);
    }
    else if (key == sf::Keyboard::D)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            sprite.move(speed, -speed);
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            sprite.move(speed, speed);
        else
            sprite.move(speed, 0);
    }

}
