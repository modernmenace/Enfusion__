#include "Slot.h"

Slot::Slot(sf::Vector2f position, Inventory* inv, float scale, Item *item) : s_sprite(), s_text("", sf::Vector2f(0, 0), 25)
{
    s_inv     = inv;
    s_item    = item;
    s_amount  = 0;
    s_scale   = scale;

    addComponent<Position>(position);
    addComponent<Sprite>("UI/ui.png");
    getComponent<Sprite>().getSprite()->setTextureRect(sf::IntRect(66, 32, 16, 16));
    getComponent<Sprite>().getSprite()->setScale(scale * 6, scale * 6);
    s_text.initialize();
    s_text.setText("");
    auto s_x = getComponent<Position>().getPosition().x + 10;
    auto s_y = getComponent<Position>().getPosition().y + 62;
    s_text.setPosition(sf::Vector2f(s_x, s_y));
}

void Slot::setItem(Item *item)
{
    s_item = item;
    if (s_item != nullptr)
    {
        s_sprite.setTexture(s_item->icon());
        s_sprite.setPosition(getComponent<Position>().getPosition());
        s_sprite.setScale(s_scale * 6, s_scale * 6);
    }
}

void Slot::activateItem()
{
    if (!s_item || !s_inv) return;

    s_item->activate();

    if(s_item->type() == Item_Consumable)
        s_inv->remove(s_item, 1);
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