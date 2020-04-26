#include "InventoryMenu.h"

/*
 *  InventoryMenu
 *
 *  DESC: Visual management of inventory
 *
 *  REQUIRES: Parent Entity has Inventory Component
 *
 */

InventoryMenu::InventoryMenu(Entity *entity) : i_tooltip()
{
    i_entity = entity;
    addComponent<Position>(sf::Vector2f(300, -450));
    addComponent<Sprite>("UI/ui.png");
}

InventoryMenu::~InventoryMenu()
{
    for(std::vector<Slot*>::iterator i = slots.begin(),
            e = slots.end(); i != e; ++i)
        delete (*i);
}

/*
 *  Initialize
 *  DESC: Initializes menu, sets up slots
 *
 *  IN:  NONE
 *
 *  OUT: NONE
 *
 */

void InventoryMenu::initialize()
{
    assert(i_entity->hasComponent<Inventory>());
    Entity::initialize();
    i_tooltip.initialize();

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

/*
 *  UpdateSlots
 *  DESC: Updates the slots with the most recent contents
 *        of the inventory
 *
 *  IN:  NONE
 *
 *  OUT: NONE
 *
 */

void InventoryMenu::updateSlots()
{
    for(int s = 0; s < slots.size(); s++)
    {
        slots[s]->setItem(i_entity->getComponent<Inventory>().item(s));
        slots[s]->setCount(i_entity->getComponent<Inventory>().amount(s));
        slots[s]->itemText()->setPosition(sf::Vector2f(slots[s]->itemSprite()->getPosition().x + 10,
                                                          slots[s]->itemSprite()->getPosition().y + 62));
    }
}

/*
 *  ToggleMenu
 *  DESC: Shows/Hides the menu
 *
 *  IN:  NONE
 *
 *  OUT: NONE
 *
 */

void InventoryMenu::toggleMenu()
{
    menuActive = !menuActive;

    if (menuActive)
    {
        updateSlots();

        getComponent<Sprite>().visible = true;
        for(auto &s : slots)
            s->setVisible(true);
    }
    else
    {
        getComponent<Sprite>().visible = false;
        for(auto &s : slots)
            s->setVisible(false);
        i_tooltip.hide();
    }
}

/*
 *  Update
 *  DESC: If menu active, checks if tooltip should be
 *        displayed
 *
 *  IN:  tickRate: current tick rate
 *
 *  OUT: NONE
 *
 */

void InventoryMenu::update(sf::Time tickRate)
{
    Entity::update(tickRate);
    if (!menuActive) return;

    if (i_mouseDown)
    {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        {
            if (i_drag)
                slots[i_dragIndex]->itemSprite()->setPosition(MousePosition);

            if(i_mouseClock.getElapsedTime().asSeconds() > DRAG_THRESHOLD_S && !i_drag)
            {
                int toDrag = -1;
                sf::Sprite& s = getComponent<Sprite>().getSprite();

                for(int s = 0; s < slots.size(); s++)
                    if (slots[s]->item() != nullptr)
                        if (slots[s]->getComponent<Sprite>().getSprite().getGlobalBounds().contains(MousePosition))
                        {
                            toDrag = s;
                            break;
                        }

                if (toDrag >= 0)
                {
                    i_tooltip.hide();
                    i_drag = true;
                    i_dragIndex = toDrag;
                }
                else
                {
                    i_drag      = false;
                    i_mouseDown = false;
                }
            }
        }
        else
        {
            if (i_drag)
            {
                sf::Sprite &i_m_s = getComponent<Sprite>().getSprite();
                if (!i_m_s.getGlobalBounds().contains(MousePosition.x, MousePosition.y))
                {
                    i_entity->getComponent<Inventory>().remove(i_dragIndex);
                    updateSlots();
                }
                else
                {
                    for(int s = 0; s < slots.size(); s++)
                    {
                        if (slots[s]->getComponent<Sprite>().getSprite().getGlobalBounds().contains(MousePosition))
                        {
                            i_entity->getComponent<Inventory>().swapItem(i_dragIndex, s);
                            updateSlots();
                        }
                    }
                }
            }

            if (!i_drag)
            {
            sf::Sprite& s = getComponent<Sprite>().getSprite();

            for(int s = 0; s < slots.size(); s++)
                if (slots[s]->item() != nullptr)
                    if (slots[s]->getComponent<Sprite>().getSprite().getGlobalBounds().contains(MousePosition))
                    {
                        i_entity->getComponent<Inventory>().activated(s);
                        slots[s]->activateItem();
                        slots.at(s)->setItem(i_entity->getComponent<Inventory>().item(s));
                        slots.at(s)->setCount(i_entity->getComponent<Inventory>().amount(s));
                    }

            }

            i_mouseDown = false;
            i_drag      = false;
            i_dragIndex = 0;
        }
    }

    if (!i_drag) {
        sf::Sprite &s = getComponent<Sprite>().getSprite();

        if (s.getGlobalBounds().contains(MousePosition))
        {
            bool f = false;
            for (int s = 0; s < slots.size(); s++)
            {
                if (slots[s]->item() != nullptr)
                {
                    if (slots[s]->getComponent<Sprite>().getSprite().getGlobalBounds().contains(MousePosition.x, MousePosition.y))
                    {
                        auto t_pos = slots[s]->getComponent<Position>().getPosition();
                        t_pos.x += 96;
                        i_tooltip.show(slots[s]->item(), t_pos);
                        f = true;
                    }
                }
            }
            if (!f) i_tooltip.hide();
        }
        else i_tooltip.hide();

    }
}

/*
 *  HandleInput
 *  DESC: Checks if slot has been clicked
 *
 *  IN:  button: Mouse button pressed
 *
 *  OUT: NONE
 *
 */

void InventoryMenu::handleInput(sf::Mouse::Button button)
{
    if(button == sf::Mouse::Left && !i_mouseDown)
    {
        i_mouseDown = true;
        i_drag      = false;
        i_mouseClock.restart();
    }
}

/*
 *  Render
 *  DESC: Renders menu/slots/tooltip
 *
 *  IN:  window: render window
 *
 *  OUT: NONE
 *
 */

void InventoryMenu::render(sf::RenderWindow *window)
{
    Entity::render(window);

    for(auto &s : slots)
        s->render(window);

    if (i_drag)
    {
        window->draw(*slots[i_dragIndex]->itemSprite());
        slots[i_dragIndex]->itemText()->setPosition(sf::Vector2f(slots[i_dragIndex]->itemSprite()->getPosition().x + 10,
                                                                 slots[i_dragIndex]->itemSprite()->getPosition().y + 62));
        slots[i_dragIndex]->itemText()->render(window);
    }

    i_tooltip.render(window);
}
