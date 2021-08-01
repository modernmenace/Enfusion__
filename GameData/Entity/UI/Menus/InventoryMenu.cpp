#include "InventoryMenu.h"
#include "../../../Engine/Lvl/LevelManager.h"
#include "../../Level/ItemPickup.h"
#include "../../../Engine/Component/Anim/AnimatedSprite.h"

/************************************************************************
 * FUNCTION :       Inventory::Inventory
 *
 * DESCRIPTION :
 *       Constructor, set up components
 *
 *  INPUTS:  Entity *entity : attatched entity
 *
 *  OUTPUTS: NONE
 *
 *  VERSION   	DATE    		WHO     DETAIL
 *  V1.00.00   	2021.01.27 	    JCB     Documentation Start
 *
 ************************************************************************/

InventoryMenu::InventoryMenu(Entity *entity) : i_tooltip(),
                                               i_playerNameDisplay("Player Name", sf::Vector2f(150, -375), 20),
                                               i_playerLevelDisplay("Level 1 (0/1000)", sf::Vector2f(150, -350), 20)
{
    i_entity = entity;
    addComponent<Position>(sf::Vector2f(-200, -450));
    addComponent<Sprite>("UI/ui.png");
    i_playerView.addComponent<Position>(sf::Vector2f(-160, -350));
    i_playerView.addComponent<AnimatedSprite>("Protagonist/base_body.png", 3, sf::IntRect(0, 0, 87, 152));
    i_playerView.getComponent<AnimatedSprite>().addLayer("Protagonist/base_head.png", Layer_Type_HEAD);

}

/************************************************************************
 * FUNCTION :       Inventory::~Inventory
 *
 * DESCRIPTION :
 *       Destructor, delete allocated slots
 *
 *  INPUTS:  NONE
 *
 *  OUTPUTS: NONE
 *
 *  VERSION   	DATE    		WHO     DETAIL
 *  V1.00.00   	2021.01.27 	    JCB     Documentation Start
 *
 ************************************************************************/

InventoryMenu::~InventoryMenu()
{
    for(std::vector<Slot*>::iterator i = slots.begin(),
            e = slots.end(); i != e; ++i)
        delete (*i);

    delete i_equipmentSlotHead;
    delete i_equipmentSlotTop;
    delete i_equipmentSlotBottom;
}

/************************************************************************
 * FUNCTION :       Inventory::initialize
 *
 * DESCRIPTION :
 *       Initializes components and set up slots
 *
 *  INPUTS:  NONE
 *
 *  OUTPUTS: NONE
 *
 *  VERSION   	DATE    		WHO     DETAIL
 *  V1.00.00   	2021.01.27 	    JCB     Documentation Start
 *
 ************************************************************************/

void InventoryMenu::initialize()
{
    assert(i_entity->hasComponent<Inventory>());
    Entity::initialize();
    i_tooltip.initialize();
    i_playerView.initialize();
    i_playerView.getComponent<AnimatedSprite>().setScale(sf::Vector2f(6, 6));



    getComponent<Sprite>().getSprite().setTextureRect(sf::IntRect(0, 0, 48, 48));
    getComponent<Sprite>().getSprite().setScale(12, 15);
    getComponent<Sprite>().setVisible(false);

    i_playerNameDisplay.initialize();
    i_playerLevelDisplay.initialize();

    //initialize slots
    sf::Vector2f slotPos(getComponent<Position>().getPosition().x + 45,
                     getComponent<Position>().getPosition().y + 350);
    for(int j = 0; j < 3; j++)
    {
        for (int i = 0; i < 5; i++)
        {
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

    //initialize equipment slots
    i_equipmentSlotHead = new Slot(sf::Vector2f(0, -350), &i_entity->getComponent<Inventory>(), 0.75);
    i_equipmentSlotTop = new Slot(sf::Vector2f(0, -275), &i_entity->getComponent<Inventory>(), 0.75);
    i_equipmentSlotBottom = new Slot(sf::Vector2f(0, -200), &i_entity->getComponent<Inventory>(), 0.75);

    //initialize starting player view
    auto* p  = LevelManager::Instance()->getCurrentLevel().player();
    auto* as = &i_playerView.getComponent<AnimatedSprite>();
    if (p->equipment()->head != nullptr)
        as->addLayer(p->equipment()->head->linkedTexture(), Layer_Type_HEAD);
    if (p->equipment()->top != nullptr)
        as->addLayer(p->equipment()->top->linkedTexture(), Layer_Type_TOP);
    if (p->equipment()->bottom != nullptr)
        as->addLayer(p->equipment()->bottom->linkedTexture(), Layer_Type_BOTTOM);

    as->switchState(0, 1);
}

/************************************************************************
 * FUNCTION :       Inventory::updateSlots
 *
 * DESCRIPTION :
 *       Updates slots with most recent contents of the inventory
 *
 *  INPUTS:  NONE
 *
 *  OUTPUTS: NONE
 *
 *  VERSION   	DATE    		WHO     DETAIL
 *  V1.00.00   	2021.01.27 	    JCB     Documentation Start
 *
 ************************************************************************/

void InventoryMenu::updateSlots()
{
    for(int s = 0; s < slots.size(); s++)
    {
        slots[s]->setItem(i_entity->getComponent<Inventory>().item(s));
        slots[s]->setCount(i_entity->getComponent<Inventory>().amount(s));
        slots[s]->itemText()->setPosition(sf::Vector2f(slots[s]->itemSprite()->getPosition().x + 10,
                                                          slots[s]->itemSprite()->getPosition().y + 62));
    }

    //update equipment slots
    Player* player = LevelManager::Instance()->getCurrentLevel().player();
    i_equipmentSlotHead->setItem(player->equipment()->head);
    i_equipmentSlotTop->setItem(player->equipment()->top);
    i_equipmentSlotBottom->setItem(player->equipment()->bottom);
}

/************************************************************************
 * FUNCTION :       Inventory::toggleMenu
 *
 * DESCRIPTION :
 *       Shows/hides the menu
 *
 *  INPUTS:  NONE
 *
 *  OUTPUTS: NONE
 *
 *  VERSION   	DATE    		WHO     DETAIL
 *  V1.00.00   	2021.01.27 	    JCB     Documentation Start
 *
 ************************************************************************/

void InventoryMenu::toggleMenu()
{
    menuActive = !menuActive;

    if (menuActive)
    {
        updateSlots();

        getComponent<Sprite>().setVisible(true);
        for(auto &s : slots)
            s->setVisible(true);

        i_equipmentSlotHead->setVisible(true);
        i_equipmentSlotTop->setVisible(true);
        i_equipmentSlotBottom->setVisible(true);
    }
    else
    {
        getComponent<Sprite>().setVisible(false);
        for(auto &s : slots)
            s->setVisible(false);

        i_equipmentSlotHead->setVisible(false);
        i_equipmentSlotTop->setVisible(false);
        i_equipmentSlotBottom->setVisible(false);

        i_tooltip.hide();
    }
}

/************************************************************************
 * FUNCTION :       Inventory::update
 *
 * DESCRIPTION :
 *       Determines whether a tool-tip should be displayed
 *
 *  INPUTS:  sf::Time tickRate | current tick rate
 *
 *  OUTPUTS: NONE
 *
 *  VERSION   	DATE    		WHO     DETAIL
 *  V1.00.00   	2021.01.27 	    JCB     Documentation Start
 *
 ************************************************************************/

void InventoryMenu::update(sf::Time tickRate)
{
    Entity::update(tickRate);
    if (!menuActive) return;

    if (i_entity->getComponent<Inventory>().changePending())
        updateSlots();

    if (i_mouseDown)
    {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        {
            if (i_drag)
            {
                //dragging, update position
                if (i_dragIndex == DRAG_EQ_HEAD_INDEX)
                    i_equipmentSlotHead->itemSprite()->setPosition(MousePosition);
                else if (i_dragIndex == DRAG_EQ_TOP_INDEX)
                    i_equipmentSlotTop->itemSprite()->setPosition(MousePosition);
                else if (i_dragIndex == DRAG_EQ_BOTTOM_INDEX)
                    i_equipmentSlotBottom->itemSprite()->setPosition(MousePosition);
                else
                    slots[i_dragIndex]->itemSprite()->setPosition(MousePosition);
            }

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

                //check for equipment drag
                if (i_equipmentSlotHead->getComponent<Sprite>().getSprite().getGlobalBounds().contains(MousePosition))
                {
                    if (LevelManager::Instance()->getCurrentLevel().player()->equipment()->head != nullptr)
                        toDrag = DRAG_EQ_HEAD_INDEX;
                }
                else if (i_equipmentSlotTop->getComponent<Sprite>().getSprite().getGlobalBounds().contains(MousePosition))
                {
                    if (LevelManager::Instance()->getCurrentLevel().player()->equipment()->top != nullptr)
                        toDrag = DRAG_EQ_TOP_INDEX;
                }
                else if (i_equipmentSlotBottom->getComponent<Sprite>().getSprite().getGlobalBounds().contains(MousePosition))
                {
                    if (LevelManager::Instance()->getCurrentLevel().player()->equipment()->bottom != nullptr)
                        toDrag = DRAG_EQ_BOTTOM_INDEX;
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
                    if (i_dragIndex == DRAG_EQ_HEAD_INDEX)
                    {
                        Player* p = LevelManager::Instance()->getCurrentLevel().player();
                        if (p->equipment()->head != nullptr)
                        {
                            LevelManager::Instance()->getCurrentLevel().addEntity(new ItemPickup(p->equipment()->head, 1));
                            p->unequipItem(Item_Clothing_Head);
                            i_playerView.getComponent<AnimatedSprite>().removeLayer(Layer_Type_HEAD);
                        }
                    }
                    else if (i_dragIndex == DRAG_EQ_TOP_INDEX)
                    {
                        Player* p = LevelManager::Instance()->getCurrentLevel().player();
                        if (p->equipment()->top != nullptr)
                        {
                            LevelManager::Instance()->getCurrentLevel().addEntity(new ItemPickup(p->equipment()->top, 1));
                            p->unequipItem(Item_Clothing_Top);
                            i_playerView.getComponent<AnimatedSprite>().removeLayer(Layer_Type_TOP);
                        }
                    }
                    else if (i_dragIndex == DRAG_EQ_BOTTOM_INDEX)
                    {
                        Player* p = LevelManager::Instance()->getCurrentLevel().player();
                        if (p->equipment()->bottom != nullptr)
                        {
                            LevelManager::Instance()->getCurrentLevel().addEntity(new ItemPickup(p->equipment()->bottom, 1));
                            p->unequipItem(Item_Clothing_Bottom);
                            i_playerView.getComponent<AnimatedSprite>().removeLayer(Layer_Type_BOTTOM);
                        }
                    }
                    else
                    {
                        i_entity->getComponent<Inventory>().drop(i_dragIndex);
                    }
                    updateSlots();
                }
                else
                {
                    bool wasSlot = false;
                    for(int s = 0; s < slots.size(); s++)
                    {
                        if (slots[s]->getComponent<Sprite>().getSprite().getGlobalBounds().contains(MousePosition))
                        {
                            if (i_dragIndex == DRAG_EQ_HEAD_INDEX)
                            {
                                Player* p = LevelManager::Instance()->getCurrentLevel().player();
                                i_entity->getComponent<Inventory>().add(p->equipment()->head);
                                p->unequipItem(Item_Clothing_Head);
                                i_playerView.getComponent<AnimatedSprite>().removeLayer(Layer_Type_HEAD);
                            }
                            else if (i_dragIndex == DRAG_EQ_TOP_INDEX)
                            {
                                Player* p = LevelManager::Instance()->getCurrentLevel().player();
                                i_entity->getComponent<Inventory>().add(p->equipment()->top);
                                p->unequipItem(Item_Clothing_Top);
                                i_playerView.getComponent<AnimatedSprite>().removeLayer(Layer_Type_TOP);
                            }
                            else if (i_dragIndex == DRAG_EQ_BOTTOM_INDEX)
                            {
                                Player* p = LevelManager::Instance()->getCurrentLevel().player();
                                i_entity->getComponent<Inventory>().add(p->equipment()->bottom);
                                p->unequipItem(Item_Clothing_Bottom);
                                i_playerView.getComponent<AnimatedSprite>().removeLayer(Layer_Type_BOTTOM);
                            }
                            else
                                i_entity->getComponent<Inventory>().swapItem(i_dragIndex, s);

                            updateSlots();
                            wasSlot = true;
                            break;
                        }
                    }
                    //if not slot still in menu
                    if (!wasSlot)
                    {
                        if (i_dragIndex == DRAG_EQ_HEAD_INDEX || i_dragIndex == DRAG_EQ_TOP_INDEX || i_dragIndex == DRAG_EQ_BOTTOM_INDEX)
                            updateSlots();
                        else if (i_equipmentSlotHead->getComponent<Sprite>().getSprite().getGlobalBounds().contains(MousePosition) ||
                            i_equipmentSlotTop->getComponent<Sprite>().getSprite().getGlobalBounds().contains(MousePosition) ||
                            i_equipmentSlotBottom->getComponent<Sprite>().getSprite().getGlobalBounds().contains(MousePosition))
                        {
                            //treating all equipment slots as the same for now
                            auto* itm = i_entity->getComponent<Inventory>().item(i_dragIndex);
                            if (itm != nullptr)
                            {
                                if (itm->type() == Item_Clothing_Top || itm->type() == Item_Clothing_Head
                                    || itm->type() == Item_Clothing_Bottom)
                                {
                                    LevelManager::Instance()->getCurrentLevel().player()->equipItem(itm);

                                    Item* itm2 = nullptr;
                                    if (itm->type() == Item_Clothing_Head)
                                    {
                                        itm2 = i_equipmentSlotHead->item();
                                        i_playerView.getComponent<AnimatedSprite>().addLayer(itm->linkedTexture(), Layer_Type_HEAD);
                                    }
                                    else if (itm->type() == Item_Clothing_Top)
                                    {
                                        itm2 = i_equipmentSlotTop->item();
                                        i_playerView.getComponent<AnimatedSprite>().addLayer(itm->linkedTexture(), Layer_Type_TOP);
                                    }
                                    else if (itm->type() == Item_Clothing_Bottom)
                                    {
                                        itm2 = i_equipmentSlotBottom->item();
                                        i_playerView.getComponent<AnimatedSprite>().addLayer(itm->linkedTexture(), Layer_Type_BOTTOM);
                                    }

                                    i_entity->getComponent<Inventory>().remove(i_dragIndex);
                                    if (itm2 != nullptr)
                                        i_entity->getComponent<Inventory>().add(itm2);

                                    updateSlots();
                                }
                            }
                        }

                        if (i_playerView.getComponent<AnimatedSprite>().getSprite()->getGlobalBounds().contains(MousePosition))
                        {
                            if (i_dragIndex != DRAG_EQ_HEAD_INDEX && i_dragIndex != DRAG_EQ_BOTTOM_INDEX
                                && i_dragIndex != DRAG_EQ_TOP_INDEX)
                            {
                                if (i_entity->getComponent<Inventory>().item(i_dragIndex) == nullptr)
                                    return;
                                auto type = i_entity->getComponent<Inventory>().item(i_dragIndex)->type();
                                if (type == Item_Consumable)
                                {
                                    i_entity->getComponent<Inventory>().activated(i_dragIndex);
                                    slots[i_dragIndex]->activateItem();
                                    slots.at(i_dragIndex)->setItem(i_entity->getComponent<Inventory>().item(i_dragIndex));
                                    slots.at(i_dragIndex)->setCount(i_entity->getComponent<Inventory>().amount(i_dragIndex));
                                }
                                else if (type == Item_Clothing_Head || type == Item_Clothing_Top
                                         || type == Item_Clothing_Bottom)
                                {
                                    auto* itm = i_entity->getComponent<Inventory>().item(i_dragIndex);
                                    LevelManager::Instance()->getCurrentLevel().player()->equipItem(itm);

                                    Item* itm2 = nullptr;
                                    if (itm->type() == Item_Clothing_Head)
                                    {
                                        itm2 = i_equipmentSlotHead->item();
                                        i_playerView.getComponent<AnimatedSprite>().addLayer(itm->linkedTexture(), Layer_Type_HEAD);
                                    }
                                    else if (itm->type() == Item_Clothing_Top)
                                    {
                                        itm2 = i_equipmentSlotTop->item();
                                        i_playerView.getComponent<AnimatedSprite>().addLayer(itm->linkedTexture(), Layer_Type_TOP);
                                    }
                                    else if (itm->type() == Item_Clothing_Bottom)
                                    {
                                        itm2 = i_equipmentSlotBottom->item();
                                        i_playerView.getComponent<AnimatedSprite>().addLayer(itm->linkedTexture(), Layer_Type_BOTTOM);
                                    }

                                    i_entity->getComponent<Inventory>().remove(i_dragIndex);
                                    if (itm2 != nullptr)
                                        i_entity->getComponent<Inventory>().add(itm2);

                                    updateSlots();
                                }
                            }
                        }
                        else
                            updateSlots();
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

                //check equipment slot hover
                if (i_equipmentSlotHead->getComponent<Sprite>().getSprite().getGlobalBounds().contains(MousePosition.x, MousePosition.y)
                    && i_equipmentSlotHead->item() != nullptr)
                {
                    auto t_pos = i_equipmentSlotHead->getComponent<Position>().getPosition();
                    t_pos.x += 96;
                    i_tooltip.show(i_equipmentSlotHead->item(), t_pos);
                    f = true;
                }
                else if (i_equipmentSlotTop->getComponent<Sprite>().getSprite().getGlobalBounds().contains(MousePosition.x, MousePosition.y)
                         && i_equipmentSlotTop->item() != nullptr)
                {
                    auto t_pos = i_equipmentSlotTop->getComponent<Position>().getPosition();
                    t_pos.x += 96;
                    i_tooltip.show(i_equipmentSlotTop->item(), t_pos);
                    f = true;
                }
                else if (i_equipmentSlotBottom->getComponent<Sprite>().getSprite().getGlobalBounds().contains(MousePosition.x, MousePosition.y)
                         && i_equipmentSlotBottom->item() != nullptr)
                {
                    auto t_pos = i_equipmentSlotBottom->getComponent<Position>().getPosition();
                    t_pos.x += 96;
                    i_tooltip.show(i_equipmentSlotBottom->item(), t_pos);
                    f = true;
                }
            }
            if (!f) i_tooltip.hide();
        }
        else i_tooltip.hide();

    }
}

/************************************************************************
 * FUNCTION :       Inventory::handleInput
 *
 * DESCRIPTION :
 *       Checks whether a slot has been clicked
 *
 *  INPUTS:  sf::Mouse::Button button | Mouse button status
 *
 *  OUTPUTS: NONE
 *
 *  VERSION   	DATE    		WHO     DETAIL
 *  V1.00.00   	2021.01.27 	    JCB     Documentation Start
 *
 ************************************************************************/

void InventoryMenu::handleInput(sf::Mouse::Button button)
{
    if(button == sf::Mouse::Left && !i_mouseDown)
    {
        i_mouseDown = true;
        i_drag      = false;
        i_mouseClock.restart();
    }
}

/************************************************************************
 * FUNCTION :       Inventory::render
 *
 * DESCRIPTION :
 *       Renders everything to the window if active
 *
 *  INPUTS:  sf::RenderWindow *window | The window
 *
 *  OUTPUTS: NONE
 *
 *  VERSION   	DATE    		WHO     DETAIL
 *  V1.00.00   	2021.01.27 	    JCB     Documentation Start
 *
 ************************************************************************/

void InventoryMenu::render(sf::RenderWindow *window, uint8_t z)
{
    if (!active()) return;
    Entity::render(window, z);

    i_playerView.render(window, z);

    for(auto &s : slots)
        s->render(window, z);

    i_equipmentSlotHead->render(window, z);
    i_equipmentSlotTop->render(window, z);
    i_equipmentSlotBottom->render(window, z);
    i_playerNameDisplay.render(window, z);
    i_playerLevelDisplay.render(window, z);

    if (i_drag)
    {
        if (i_dragIndex == DRAG_EQ_HEAD_INDEX)
        {
            window->draw(*i_equipmentSlotHead->itemSprite());
            i_equipmentSlotHead->itemText()->setPosition(sf::Vector2f(i_equipmentSlotHead->itemSprite()->getPosition().x + 10,
                                                                      i_equipmentSlotHead->itemSprite()->getPosition().y + 62));
            i_equipmentSlotHead->itemText()->render(window, z);
        }
        else if (i_dragIndex == DRAG_EQ_TOP_INDEX)
        {
            window->draw(*i_equipmentSlotTop->itemSprite());
            i_equipmentSlotTop->itemText()->setPosition(sf::Vector2f(i_equipmentSlotTop->itemSprite()->getPosition().x + 10,
                                                                      i_equipmentSlotTop->itemSprite()->getPosition().y + 62));
            i_equipmentSlotTop->itemText()->render(window, z);
        }
        else if (i_dragIndex == DRAG_EQ_BOTTOM_INDEX)
        {
            window->draw(*i_equipmentSlotBottom->itemSprite());
            i_equipmentSlotBottom->itemText()->setPosition(sf::Vector2f(i_equipmentSlotBottom->itemSprite()->getPosition().x + 10,
                                                                      i_equipmentSlotBottom->itemSprite()->getPosition().y + 62));
            i_equipmentSlotBottom->itemText()->render(window, z);
        }
        else
        {
            window->draw(*slots[i_dragIndex]->itemSprite());
            slots[i_dragIndex]->itemText()->setPosition(sf::Vector2f(slots[i_dragIndex]->itemSprite()->getPosition().x + 10,
                                                                     slots[i_dragIndex]->itemSprite()->getPosition().y + 62));
            slots[i_dragIndex]->itemText()->render(window, z);
        }
    }

    i_tooltip.render(window, z);
}
