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

sf::Vector2f Entity::getMousePosition()
{
    //if (!uiView) return sf::Vector2f(0, 0);
    auto oldView = WINDOW->getView();
    WINDOW->setView(*uiView);
    sf::Vector2f m_w_pos = WINDOW->mapPixelToCoords(sf::Mouse::getPosition(*WINDOW));
    WINDOW->setView(oldView);
    return m_w_pos;
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

void Entity::handleInput(sf::Mouse::Button button)
{
    for(auto& c : componentMap)
        c.second->handleInput(button);
}