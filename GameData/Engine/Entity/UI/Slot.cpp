#include "Slot.h"

Slot::Slot(sf::Vector2f position, Item *item) : s_sprite()
{
    s_item = item;

    addComponent<Position>(position);
    addComponent<Sprite>("UI/windowsheet.png");
    getComponent<Sprite>().getSprite().setTextureRect(sf::IntRect(64, 32, 16, 16));
    getComponent<Sprite>().getSprite().setScale(6, 6);
}

void Slot::setItem(Item *item)
{
    s_item = item;
    if (s_item != nullptr)
    {
        s_sprite.setTexture(s_item->icon());
        s_sprite.setPosition(getComponent<Position>().getPosition());
        s_sprite.setScale(6, 6);
    }
}

void Slot::render(sf::RenderWindow *window)
{
    if (s_visible)
    {
        Entity::render(window);
        if (item() != nullptr)
            window->draw(s_sprite);
    }
}