#include "Hotbar.h"

Hotbar::Hotbar(sf::Vector2f position)
{
    addComponent<Position>(position);
    addComponent<Sprite>("UI/windowsheet.png");
}

void Hotbar::initialize()
{
    //need specific piece of sheet, and need to scale
    getComponent<Sprite>().getSprite().setTextureRect(sf::IntRect(0, 48, 48, 16));
    getComponent<Sprite>().getSprite().setScale(15, 10);

    Entity::initialize();
}