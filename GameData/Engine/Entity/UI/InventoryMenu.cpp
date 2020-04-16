#include "InventoryMenu.h"

//TODO | Clicking on items is very bad and seemingly random
//TODO | Maybe Issue is that it isnt using UI view?
//TODO | Click position changes based on player position

InventoryMenu::InventoryMenu(Entity *entity)
{
    i_entity = entity;
    addComponent<Position>(sf::Vector2f(300, -450));
    addComponent<Sprite>("UI/windowsheet.png");
}

void InventoryMenu::initialize()
{
    assert(i_entity->hasComponent<Inventory>());
    Entity::initialize();

    getComponent<Sprite>().getSprite().setTextureRect(sf::IntRect(0, 0, 48, 48));
    getComponent<Sprite>().getSprite().setScale(12, 15);
    getComponent<Sprite>().visible = false;

    //initialize slots
    sf::Vector2f slotPos(getComponent<Position>().getPosition().x + 45,
                     getComponent<Position>().getPosition().y + 350);
    for(int j = 0; j < 3; j++) {
        for (int i = 0; i < 5; i++) {
            Slot *s = new Slot(slotPos, &i_entity->getComponent<Inventory>());
            s->setVisible(false);
            slots.emplace_back(s);
            slotPos.x += 96;
        }
        slotPos.x = getComponent<Position>().getPosition().x + 45;
        slotPos.y += 96;
    }

    for(int s = 0; s < slots.size(); s++)
        slots.at(s)->setItem(i_entity->getComponent<Inventory>().item(s));
}

void InventoryMenu::updateSlots()
{
    for(int s = 0; s < slots.size(); s++)
        slots.at(s)->setItem(i_entity->getComponent<Inventory>().item(s));

    for(int s = 0; s < slots.size(); s++)
        slots.at(s)->setCount(i_entity->getComponent<Inventory>().amount(s));
}

void InventoryMenu::toggleMenu()
{
    menuActive = !menuActive;

    if (menuActive)
    {
        for(int s = 0; s < slots.size(); s++)
            slots.at(s)->setItem(i_entity->getComponent<Inventory>().item(s));

        for(int s = 0; s < slots.size(); s++)
            slots.at(s)->setCount(i_entity->getComponent<Inventory>().amount(s));

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

void InventoryMenu::update(sf::Time tickRate)
{
    Entity::update(tickRate);
    if (!menuActive) return;

    //faster way?
    sf::Vector2f m_w_pos = WINDOW->mapPixelToCoords(sf::Mouse::getPosition(*WINDOW));
    sf::Sprite& s = getComponent<Sprite>().getSprite();
    m_w_pos.x -= (s.getTextureRect().width * s.getScale().x);
    m_w_pos.x -= 25;  // using magic number
    m_w_pos.y -= 300; // doing it again

    //first check if it is within menus bounds
    if (s.getGlobalBounds().contains(m_w_pos.x, m_w_pos.y))
    {
        for(int s = 0; s < slots.size(); s++)
        {
            if (slots[s]->item() != nullptr)
            {
                if (slots[s]->getComponent<Sprite>().getSprite().getGlobalBounds().contains(m_w_pos.x, m_w_pos.y))
                {
                    //currently hovering over slot[s], show tooltip
                }
            }
        }
    }
}

void InventoryMenu::handleInput(sf::Keyboard::Key key)
{
    if (key == 60) toggleMenu();
}

void InventoryMenu::handleInput(sf::Mouse::Button button)
{
    //check for left click
    if(button == sf::Mouse::Left)
    {
        sf::Vector2f m_w_pos = WINDOW->mapPixelToCoords(sf::Mouse::getPosition(*WINDOW));
        sf::Sprite& s = getComponent<Sprite>().getSprite();
        m_w_pos.x -= (s.getTextureRect().width * s.getScale().x);
        m_w_pos.x -= 25;  // using magic number
        m_w_pos.y -= 300; // doing it again
        for(int s = 0; s < slots.size(); s++)
            if (slots[s]->item() != nullptr)
                if (slots[s]->getComponent<Sprite>().getSprite().getGlobalBounds().contains(m_w_pos.x, m_w_pos.y))
                {
                    i_entity->getComponent<Inventory>().activated(s);
                    slots[s]->activateItem();
                    slots.at(s)->setItem(i_entity->getComponent<Inventory>().item(s));
                    slots.at(s)->setCount(i_entity->getComponent<Inventory>().amount(s));
                }
    }
}

void InventoryMenu::render(sf::RenderWindow *window)
{
    Entity::render(window);

    for(auto &s : slots)
        s->render(window);
}
