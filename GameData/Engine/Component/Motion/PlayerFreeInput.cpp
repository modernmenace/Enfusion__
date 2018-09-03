#include "PlayerFreeInput.h"

/*
 *  Player Free Input Component
 *
 *  DESC: Allows for input-based free movement (WSAD/Numpad)
 *
 *  TODO: SPRITE IS CURRENTLY A UNSAFE POINTER, NOT WORKING OTHERWISE
 *
 */

PlayerFreeInput::PlayerFreeInput(int speed)
{
    this->speed = speed;
}

void PlayerFreeInput::initialize()
{
    this->sprite = &entity->getComponent<Sprite>().getSprite();
}

void PlayerFreeInput::handleInput(sf::Keyboard::Key key)
{
    if (key == sf::Keyboard::W)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            sprite->move(-speed, -speed);
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            sprite->move(speed, -speed);
        else
            sprite->move(0, -speed);
    }
    else if (key == sf::Keyboard::A)
    {
        if (currentDirection == MovementDirection::RIGHT)
            flipSprite();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            sprite->move(-speed, -speed);
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            sprite->move(-speed, speed);
        else
            sprite->move(-speed, 0);

        currentDirection = MovementDirection::LEFT;
    }
    else if (key == sf::Keyboard::S)
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            sprite->move(-speed, speed);
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            sprite->move(speed, speed);
        else
            sprite->move(0, speed);
    }
    else if (key == sf::Keyboard::D)
    {
        if (currentDirection == MovementDirection::LEFT)
            flipSprite();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            sprite->move(speed, -speed);
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            sprite->move(speed, speed);
        else
            sprite->move(speed, 0);

        currentDirection = MovementDirection::RIGHT;
    }
}