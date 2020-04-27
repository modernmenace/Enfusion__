#include "Minimap.h"

Minimap::Minimap()
{
    addComponent<Position>(sf::Vector2f(650, -525));
    addComponent<Sprite>("UI/ui.png");
    getComponent<Sprite>().getSprite().setTextureRect(sf::IntRect(0, 0, 48, 48));
    getComponent<Sprite>().getSprite().setScale(6, 6);
}

void Minimap::initialize()
{
    Entity::initialize();
}

void Minimap::render(sf::RenderWindow* window)
{
    Entity::render(window);
}
