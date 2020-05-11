#include "Player.h"
#include "../Component/Anim/AnimatedSprite.h"
#include "../Component/Base/Position.h"
#include "../Component/Motion/AnimatedMovement.h"
#include "../Component/Misc/Camera.h"
#include "../Component/Misc/Inventory.h"

Player::Player(string_t spriteName, sf::Vector2f position)
{
    addComponent<Position>(position);
    addComponent<AnimatedSprite>(spriteName, 4, 3, sf::IntRect(0, 0, 180, 256));
    addComponent<Camera>(CameraType::FOLLOW);
    addComponent<AnimatedMovement>();
    addComponent<Inventory>();
}

sf::FloatRect Player::bounds()
{
    return getComponent<AnimatedSprite>().getSprite().getGlobalBounds();
}