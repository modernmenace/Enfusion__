#include "Collider.h"

Collider::Collider(sf::IntRect range, void (*collision)(Entity*))
{
    c_box = range;
    c_collision = collision;
}

bool Collider::checkForCollision(sf::IntRect *obj, Entity *other)
{
    if (c_box.intersects(*obj))
    {
        onCollision(other);
    }
}