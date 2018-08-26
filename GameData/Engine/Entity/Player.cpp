#include "Player.h"

Player::Player(std::string spriteName, sf::Vector2f position) :
                    animator(Animator::AnimatorType::PLAYER, sf::IntRect(0, 0, 32, 64))
{
    // setup player animations
    animator.setupAnimator(std::map<Animator::Animations, sf::Texture>
            {
                    { Animator::Animations::IDLE, AssetManager::getTexture(RESOURCE_PATH_OBJECT + std::string("Anim/Player_Walk.png")) },
                    { Animator::Animations::WALK, AssetManager::getTexture(RESOURCE_PATH_OBJECT + std::string("Anim/Player_Walk.png")) }
            });

    switchState(State::IDLE);

    addComponent<Position>(position);
    addComponent<Sprite>(spriteName);
    addComponent<PlayerFreeInput>();
}

void Player::update()
{
    Entity::update();
    //animator.update(&sprite);
}

void Player::switchState(State nextState)
{
    //animator.setSpriteAnimation(&sprite, animStateMap.at(nextState));
    currentState = nextState;
}
