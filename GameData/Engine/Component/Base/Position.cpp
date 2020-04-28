#include "Position.h"
#include "Sprite.h"
#include "../Anim/AnimatedSprite.h"

Position::Position(sf::Vector2f position)
{
    this->position = position;
}

void Position::setPosition(sf::Vector2f pos)
{
    this->position = pos;
    if (entity->hasComponent<Sprite>())
        entity->getComponent<Sprite>().updatePosition(position);
    if (entity->hasComponent<AnimatedSprite>())
        entity->getComponent<AnimatedSprite>().setPosition(position);
}