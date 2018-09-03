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