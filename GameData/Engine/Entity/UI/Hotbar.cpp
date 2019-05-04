#include "Hotbar.h"

/*
 *  Hotbar
 *
 *  NOTE: This could use the ECS much more efficiently,
 *        but it serves its purpose for now
 *
 *
 */

Hotbar::Hotbar(sf::Vector2f position)
{
    addComponent<Position>(position);
    addComponent<Sprite>("UI/windowsheet.png");

    Vector2f slotPos(position.x + 75, position.y + 20);
    for(int i = 0; i < HOTBAR_SLOTS; i++)
    {
        Slot s;
        s.sprite = sf::Sprite(AssetManager::getTexture("UI/windowsheet.png"));
        s.sprite.setTextureRect(sf::IntRect(64, 32, 16, 16));
        s.sprite.setScale(6, 6);
        s.sprite.setPosition(slotPos);
        slotPos.x += 96; //16 * x-scale
        slots.emplace_back(s);
    }
}

void Hotbar::initialize()
{
    //need specific piece of sheet, and need to scale
    getComponent<Sprite>().getSprite().setTextureRect(sf::IntRect(0, 48, 48, 16));
    getComponent<Sprite>().getSprite().setScale(15, 10);

    Entity::initialize();
}

void Hotbar::render(sf::RenderWindow *window)
{
    Entity::render(window);

    for(auto &s : slots)
        window->draw(s.sprite);
}