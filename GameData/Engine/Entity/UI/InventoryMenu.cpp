#include "InventoryMenu.h"

InventoryMenu::InventoryMenu(Entity *entity)
{
    i_entity = entity;
    addComponent<Position>(sf::Vector2f(300, -450));
    addComponent<Sprite>("UI/windowsheet.png");
}

void InventoryMenu::initialize()
{
    assert(i_entity->hasComponent<Inventory>());

    getComponent<Sprite>().getSprite().setTextureRect(sf::IntRect(0, 0, 48, 48));
    getComponent<Sprite>().getSprite().setScale(12, 15);
    getComponent<Sprite>().visible = false;
}

void InventoryMenu::toggleMenu()
{
    //TODO: Global controls file
    menuActive = !menuActive;

    if (menuActive)
    {
        getComponent<Sprite>().visible = true;
    }
    else
    {
        getComponent<Sprite>().visible = false;
    }



}

void InventoryMenu::handleInput(sf::Keyboard::Key key)
{
    if (key == 60) toggleMenu();
}
