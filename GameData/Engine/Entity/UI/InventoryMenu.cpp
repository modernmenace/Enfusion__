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

    //initialize slots
    Vector2f slotPos(getComponent<Position>().getPosition().x + 45,
                     getComponent<Position>().getPosition().y + 350);
    for(int j = 0; j < 3; j++) {
        for (int i = 0; i < 5; i++) {
            Slot *s = new Slot(slotPos);
            s->setVisible(false);
            slots.emplace_back(s);
            slotPos.x += 96;
        }
        slotPos.x = getComponent<Position>().getPosition().x + 45;
        slotPos.y += 96;
    }
}

void InventoryMenu::toggleMenu()
{
    //TODO: Global controls file
    menuActive = !menuActive;

    if (menuActive)
    {
        for(int s = 0; s < slots.size(); s++)
            slots.at(s)->setItem(i_entity->getComponent<Inventory>().item(s));

        getComponent<Sprite>().visible = true;
        for(auto &s : slots)
            s->setVisible(true);
    }
    else
    {
        getComponent<Sprite>().visible = false;
        for(auto &s : slots)
            s->setVisible(false);
    }



}

void InventoryMenu::handleInput(sf::Keyboard::Key key)
{
    if (key == 60) toggleMenu();
}

void InventoryMenu::render(sf::RenderWindow *window)
{
    Entity::render(window);

    for(auto &s : slots)
        s->render(window);
}
