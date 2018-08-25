#include "Entity.h"
#include "../Component/Base/Sprite.h"

/*
 *  Entity
 *
 *  DESC: Base class for all entities, contains virtual functions
 *
 *  NOTE: Switched from vector to map for components, is this
 *        much slower?
 *
 *  USAGE: < Coming Soon >
 */

Entity::Entity()
{

}

void Entity::update()
{
    for(auto& c : componentMap)
        c.second->update();
}

void Entity::render(sf::RenderWindow *window)
{
    for (auto& c : componentMap)
        c.second->render(window);
}