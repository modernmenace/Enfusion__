#include "Agent.h"

Agent::Agent(std::string spriteName, sf::Vector2f position)
{
    this->sprite = sf::Sprite(AssetManager::getTexture(RESOURCE_PATH_AI + spriteName));
    this->position = position;
    this->sprite.setPosition(this->position);
    this->sprite.setScale(GLOBAL_SCALE_GAMEOBJECT);
}

void Agent::render(sf::RenderWindow *window)
{
    window->draw(sprite);
}