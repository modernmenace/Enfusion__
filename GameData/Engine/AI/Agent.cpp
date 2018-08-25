#include "Agent.h"
#include "../Component/Base/Position.h"

Agent::Agent(std::string spriteName, sf::Vector2f position)
{
    this->position = position;
    addComponent<Position>(position);
    addComponent<Sprite>(spriteName);
}

void Agent::render(sf::RenderWindow *window)
{
    Entity::render(window);
}