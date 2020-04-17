#include "InventoryMenu.h"
#include "../../Lvl/LevelManager.h"

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
    addComponent<Sprite>("UI/windowsheet.png");
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
        slots.at(s)->setItem(i_entity->getComponent<Inventory>().item(s));

    for(int s = 0; s < slots.size(); s++)
        slots.at(s)->setCount(i_entity->getComponent<Inventory>().amount(s));
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
        LevelManager::Instance()->getCurrentLevel().setState(GameState::PAUSE);
        updateSlots();

        getComponent<Sprite>().visible = true;
        for(auto &s : slots)
            s->setVisible(true);
    }
    else
    {
        LevelManager::Instance()->getCurrentLevel().setState(GameState::RUNNING);
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
                slots[i_dragIndex]->itemSprite()->setPosition(getMousePosition());

            if(i_mouseClock.getElapsedTime().asSeconds() > 0.3 && !i_drag)
            {
                int toDrag = -1;
                sf::Vector2f m_w_pos = getMousePosition();
                sf::Sprite& s = getComponent<Sprite>().getSprite();

                for(int s = 0; s < slots.size(); s++)
                    if (slots[s]->item() != nullptr)
                        if (slots[s]->getComponent<Sprite>().getSprite().getGlobalBounds().contains(m_w_pos))
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
                //TODO: Done dragging
                auto m_w_pos = getMousePosition();

                sf::Sprite &i_m_s = getComponent<Sprite>().getSprite();
                if (!i_m_s.getGlobalBounds().contains(m_w_pos.x, m_w_pos.y))
                {
                    i_entity->getComponent<Inventory>().remove(i_dragIndex);
                    updateSlots();
                }
                else
                {
                    //TODO: Check for new slot
                    dbg_log("else")
                    for(int s = 0; s < slots.size(); s++)
                        if (slots[s]->item() != nullptr)
                            if (slots[s]->getComponent<Sprite>().getSprite().getGlobalBounds().contains(m_w_pos))
                            {
                                //slots[s] is the new slot
                                //this only works when its the original slot
                                dbg_log(s)
                            }
                }
            }

            i_mouseDown = false;
            i_drag      = false;

            sf::Vector2f m_w_pos = getMousePosition();
            sf::Sprite& s = getComponent<Sprite>().getSprite();

            for(int s = 0; s < slots.size(); s++)
                if (slots[s]->item() != nullptr)
                    if (slots[s]->getComponent<Sprite>().getSprite().getGlobalBounds().contains(m_w_pos))
                    {
                        i_entity->getComponent<Inventory>().activated(s);
                        slots[s]->activateItem();
                        slots.at(s)->setItem(i_entity->getComponent<Inventory>().item(s));
                        slots.at(s)->setCount(i_entity->getComponent<Inventory>().amount(s));
                    }
        }
    }

    if (!i_drag) {
        sf::Sprite &s = getComponent<Sprite>().getSprite();

        sf::Vector2f m_w_pos = getMousePosition();
        i_tooltip.hide();

        if (s.getGlobalBounds().contains(m_w_pos.x, m_w_pos.y))
        {
            for (int s = 0; s < slots.size(); s++)
            {
                if (slots[s]->item() != nullptr)
                {
                    if (slots[s]->getComponent<Sprite>().getSprite().getGlobalBounds().contains(m_w_pos.x, m_w_pos.y))
                    {
                        auto t_pos = slots[s]->getComponent<Position>().getPosition();
                        t_pos.x += 96;
                        i_tooltip.show(slots[s]->item(), t_pos);
                    }
                }
            }
        }
    }
}

/*
 *  HandleInput
 *  DESC: Checks for toggle key
 *
 *  IN:  key: key pressed
 *
 *  OUT: NONE
 *
 */

void InventoryMenu::handleInput(sf::Keyboard::Key key)
{
    if (key == 60) toggleMenu();
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

    i_tooltip.render(window);

    if (i_drag)
        window->draw(*slots[i_dragIndex]->itemSprite());
}
