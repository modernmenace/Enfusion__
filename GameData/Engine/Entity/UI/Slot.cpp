#include "Slot.h"

Slot::Slot(sf::Vector2f position, Item *item) : s_sprite(), s_text("", sf::Vector2f(0, 0), 25)
{
    s_item     = item;
    s_amount   = 0;

    addComponent<Position>(position);
    addComponent<Sprite>("UI/windowsheet.png");
    getComponent<Sprite>().getSprite().setTextureRect(sf::IntRect(64, 32, 16, 16));
    getComponent<Sprite>().getSprite().setScale(6, 6);
    s_text.initialize();
    s_text.setText("");
    auto s_x = getComponent<Position>().getPosition().x + (69);
    auto s_y = getComponent<Position>().getPosition().y + (62);
    s_text.setPosition(sf::Vector2f(s_x, s_y));
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

void Slot::setCount(int c)
{
    s_amount = c;
    if (s_amount > 1)
        s_text.setText(std::to_string(s_amount));
    else
        s_text.setText("");
}

void Slot::render(sf::RenderWindow *window)
{
    if (s_visible)
    {
        Entity::render(window);
        if (item() != nullptr)
            window->draw(s_sprite);

        s_text.render(window);
    }
}