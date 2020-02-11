#include "InventoryMenu.h"

InventoryMenu::InventoryMenu(Entity *entity)
{
    i_entity = entity;
}

void InventoryMenu::initialize()
{
    // ensure there is an inventory to use
    assert(i_entity->hasComponent<Inventory>());
}

void InventoryMenu::toggleMenu()
{
    //TODO: Global controls file
    //this works, toggled with TAB key
    menuActive = !menuActive;




}

void InventoryMenu::handleInput(sf::Keyboard::Key key)
{
    if (key == 60) toggleMenu();
}
