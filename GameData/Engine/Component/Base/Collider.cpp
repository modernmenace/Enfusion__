#include "Collider.h"
#include "Sprite.h"

Collider::Collider(sf::FloatRect range, void (*collision)(Entity*))
{
    c_box = range;
    c_collision = collision;
}