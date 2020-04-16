#include "Tooltip.h"

Tooltip::Tooltip()
{
    addComponent<Position>(sf::Vector2f(0, -0));
    addComponent<Sprite>("UI/windowsheet.png");
}

void Tooltip::initialize()
{
    dbg_log("init");
    getComponent<Sprite>().getSprite().setTextureRect(sf::IntRect(0, 0, 48, 48));
    getComponent<Sprite>().getSprite().setScale(4, 4);
    getComponent<Sprite>().visible = false;
}

void Tooltip::show(Item* item, sf::Vector2f position)
{
    getComponent<Position>().setPosition(position);
    getComponent<Sprite>().getSprite().setPosition(position);
    getComponent<Sprite>().visible = true;

    //TODO: show item text
    
}