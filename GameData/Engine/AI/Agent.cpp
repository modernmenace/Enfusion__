#include "Agent.h"

Agent::Agent(std::string spriteName, sf::Vector2f position) : Entity(position)
{
    this->position = position;
    addComponent<Sprite>(spriteName);
}

void Agent::render(sf::RenderWindow *window)
{
    Entity::render(window);
}