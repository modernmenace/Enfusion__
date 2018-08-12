#include "GameObject.h"

/*
 *  GameObject
 *
 *  DESC: Base class for all game objects, contains virtual functions
 *
 *  NOTE: This class will definitely be expanded in the future
 *
 *  USAGE: All game objects inherit from this base class
 *          EX: Rock(sf::Vector2f position) : public GameObject("Rock.png", position);
 */

GameObject::GameObject(std::string spriteName, sf::Vector2f position)
{
    this->sprite = sf::Sprite(AssetManager::getTexture(RESOURCE_PATH_OBJECT + spriteName));
    this->position = position;
    this->sprite.setPosition(this->position);
    this->sprite.setScale(GLOBAL_SCALE_GAMEOBJECT);
}

void GameObject::render(sf::RenderWindow *window)
{
    window->draw(sprite);
}