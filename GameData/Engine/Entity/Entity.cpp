#include "Entity.h"
#include "../Component/Base/Sprite.h"

/*
 *  Entity
 *
 *  DESC: Base class for all entities, contains virtual functions
 *
 *  NOTE: This class will definitely be expanded in the future
 *
 *  USAGE: < Coming Soon >
 */

Entity::Entity(sf::Vector2f position)
{
    this->position = position;
}

void Entity::update()
{
    for (auto& c : components)
        c->update();
}

void Entity::render(sf::RenderWindow *window)
{
    for (auto& c : components)
        c->render(window);
}