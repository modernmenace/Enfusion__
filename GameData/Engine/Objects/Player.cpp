#include "Player.h"

Player::Player(std::string spriteName, sf::Vector2f position) : GameObject(spriteName, position)
{
    // setup player animations
    animator.setupAnimator(std::map<Animator::Animations, sf::Texture>
            {
                    { Animator::Animations::IDLE, AssetManager::getTexture(RESOURCE_PATH_OBJECT + std::string("Anim/Player_Walk.gif")) },
                    { Animator::Animations::WALK, AssetManager::getTexture(RESOURCE_PATH_OBJECT + std::string("Anim/Player_Walk.gif")) }
            });

    switchState(State::IDLE);
}

void Player::update()
{
    // handle state switching ??

}

void Player::switchState(State nextState)
{
    // apparently sfml has no gif support, move to animated sprite sheets
    sprite.setTexture(animator.getAnimation(animStateMap.at(nextState)));
    currentState = nextState;
}

void Player::handleInput(sf::Keyboard::Key key) {
    // holy shit is this buggy
    // please come back to this

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
