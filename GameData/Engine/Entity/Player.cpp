#include "Player.h"

Player::Player(std::string spriteName, sf::Vector2f position) : Entity(spriteName, position),
                    animator(Animator::AnimatorType::PLAYER, sf::IntRect(0, 0, 32, 64))
{
    // setup player animations
    animator.setupAnimator(std::map<Animator::Animations, sf::Texture>
            {
                    { Animator::Animations::IDLE, AssetManager::getTexture(RESOURCE_PATH_OBJECT + std::string("Anim/Player_Walk.png")) },
                    { Animator::Animations::WALK, AssetManager::getTexture(RESOURCE_PATH_OBJECT + std::string("Anim/Player_Walk.png")) }
            });

    switchState(State::IDLE);

    addComponent<Sprite>();
}

void Player::update()
{
    Entity::update();
    animator.update(&sprite);

}

void Player::switchState(State nextState)
{
    animator.setSpriteAnimation(&sprite, animStateMap.at(nextState));
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
        if (currentDirection == MovementDirection::RIGHT)
            FLIP_SPRITE(sprite)

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            sprite.move(-speed, -speed);
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            sprite.move(-speed, speed);
        else
            sprite.move(-speed, 0);

        currentDirection = MovementDirection::LEFT;
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
        if (currentDirection == MovementDirection::LEFT)
            FLIP_SPRITE(sprite)

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            sprite.move(speed, -speed);
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            sprite.move(speed, speed);
        else
            sprite.move(speed, 0);

        currentDirection = MovementDirection::RIGHT;
    }

}
