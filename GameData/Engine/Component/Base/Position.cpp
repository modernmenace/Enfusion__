#include "Position.h"

Position::Position(Vector2f position)
{
    this->position = position;
}

Vector2f Position::getPosition()
{
    //try using origin
    return this->position;
}

Vector2f Position::getPosition(sf::Sprite* sprite)
{
    // TODO: Work more on this
    // Maybe well have to deal with scale? Probably not
    // + sprite.width / 2 || + sprite.height / 2
    dbg_log("Calling overloaded position function")
    dbg_log(sprite->getTexture()->getSize().x << ", " << sprite->getTexture()->getSize().y)
    return (sf::Vector2f(this->position.x - (sprite->getTexture()->getSize().x / 2),
                         this->position.y - (sprite->getTexture()->getSize().y / 2)));
}