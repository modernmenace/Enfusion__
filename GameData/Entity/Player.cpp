#include "Player.h"
#include "../Engine/Component/Anim/AnimatedSprite.h"
#include "../Engine/Component/Base/Position.h"
#include "../Engine/Component/Motion/AnimatedMovement.h"
#include "../Engine/Component/Misc/Camera.h"
#include "../Component/Inventory.h"
#include "../Engine/Lvl/LevelManager.h"

Player::Player(sf::Vector2f position)
{
    addComponent<Position>(position);
    addComponent<AnimatedSprite>("Objects/chara2.png", 4, 3, sf::IntRect(0, 0, 78, 146), sf::Vector2i(1, 0));
    addComponent<Camera>(CameraType::FOLLOW);
    addComponent<AnimatedMovement>(true);
    addComponent<Inventory>();

    LevelManager::Instance()->setPlayer(this);
}

void Player::stopMovement()
{
    getComponent<AnimatedMovement>().setMoving(false);
}

sf::FloatRect* Player::collider()
{
    return getComponent<AnimatedMovement>().collider();
}

sf::FloatRect Player::bounds()
{
    return getComponent<AnimatedSprite>().getSprite().getGlobalBounds();
}

sf::Vector2f Player::currentPosition()
{
    return getComponent<AnimatedSprite>().getSprite().getPosition();
}

bool Player::isMoving()
{
    return getComponent<AnimatedMovement>().isMoving();
}