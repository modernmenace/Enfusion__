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

Entity::~Entity()
{
    //TODO: Write destructors
}

void Entity::update(sf::Time tickRate)
{
    for(auto& c : componentMap)
        c.second->update(tickRate);
}

void Entity::render(sf::RenderWindow *window)
{
    for (auto& c : componentMap)
        c.second->render(window);
}

void Entity::handleInput(sf::Keyboard::Key key)
{
    for(auto& c : componentMap)
        c.second->handleInput(key);
}