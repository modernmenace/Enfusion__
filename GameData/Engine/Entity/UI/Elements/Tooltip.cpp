#include "Tooltip.h"

/*
 *  Tooltip
 *
 *  DESC: Item tooltip UI
 *
 *  REQUIRES: NONE
 *
 */

Tooltip::Tooltip() : t_iName("", sf::Vector2f(0, 0), 20),
                     t_iDesc("", sf::Vector2f(0, 0), 15, sf::RectangleShape(sf::Vector2f(48, 48)))
{
    addComponent<Position>(sf::Vector2f(0, -0));
    addComponent<Sprite>("UI/ui.png");
}

void Tooltip::initialize()
{
    getComponent<Sprite>().getSprite().setTextureRect(sf::IntRect(0, 0, 48, 48));
    getComponent<Sprite>().getSprite().setScale(4, 4);

    t_iName.initialize();
    t_iDesc.initialize();
}

void Tooltip::show(Item* item, sf::Vector2f position)
{
    getComponent<Position>().setPosition(position);
    getComponent<Sprite>().getSprite().setPosition(position);
    getComponent<Sprite>().visible = true;

    t_iName.setText(item->name());
    t_iDesc.setText(item->description());

    sf::Vector2f pos = getComponent<Position>().getPosition();
    pos.x += 15;
    pos.y += 10;
    t_iName.setPosition(pos);
    pos.y += 30;
    t_iDesc.setPosition(pos);

    t_visible = true;
}

void Tooltip::render(sf::RenderWindow* window)
{
    if (!t_visible) return;
    Entity::render(window);

    t_iName.render(window);
    t_iDesc.render(window);
}