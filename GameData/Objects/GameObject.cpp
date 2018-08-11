#include "GameObject.h"

GameObject::GameObject(std::string spriteName, sf::Vector2f position)
{
    this->sprite = sf::Sprite(AssetManager::getTexture(RESOURCE_PATH_OBJECT + spriteName));
    this->position = position;
    this->sprite.setPosition(this->position);
}

void GameObject::render(sf::RenderWindow *window)
{
    window->draw(sprite);
}