#include "Entity.h"

/*
 *  Entity
 *
 *  DESC: Base class for all entities, contains virtual functions
 *
 *  NOTE: This class will definitely be expanded in the future
 *        TODO: Turn sprite into its own component
 *
 *  USAGE: All entities inherit from this base class
 *          EX: Rock(sf::Vector2f position) : public Entity("Rock.png", position);
 */

Entity::Entity(std::string spriteName, sf::Vector2f position)
{
    this->sprite = sf::Sprite(AssetManager::getTexture(RESOURCE_PATH_OBJECT + spriteName));
    this->position = position;
    this->sprite.setPosition(this->position);
    this->sprite.setScale(GLOBAL_SCALE_GAMEOBJECT);
}

void Entity::initialize()
{

}

void Entity::update()
{
    for (auto& c : components)
        c->update();
}

void Entity::render(sf::RenderWindow *window)
{
    window->draw(sprite);
    for (auto& c : components)
        c->render(window);
}

void Entity::addComponent(Component *c)
{
    //TODO:Check components dont exceed max size, initialize, add to vector (push_back)
}