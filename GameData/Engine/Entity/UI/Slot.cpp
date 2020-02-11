#include "Slot.h"

Slot::Slot(sf::Vector2f position, Item *item)
{
    s_item = item;

    addComponent<Position>(position);
    addComponent<Sprite>("UI/windowsheet.png");
    getComponent<Sprite>().getSprite().setTextureRect(sf::IntRect(64, 32, 16, 16));
    getComponent<Sprite>().getSprite().setScale(6, 6);
}