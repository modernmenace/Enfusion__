#include "Player.h"
#include "../Engine/Component/Anim/AnimatedSprite.h"
#include "../Engine/Component/Base/Position.h"
#include "../Engine/Component/Motion/AnimatedMovement.h"
#include "../Engine/Component/Misc/Camera.h"
#include "../Component/Inventory.h"

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