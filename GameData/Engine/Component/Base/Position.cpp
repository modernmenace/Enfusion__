#include "Position.h"

Position::Position(Vector2f position)
{
    this->position = position;
}

Vector2f Position::getPosition()
{
    return this->position;
}