#include "Hotbar.h"
#include "../../../Engine/Lvl/LevelManager.h"
#include "../../../Engine/Component/Base/Sprite.h"
#include "../../../Engine/Component/Base/Position.h"
#include "../../../Component/Inventory.h"

/*
 *  Hotbar
 *
 *  NOTE: This could use the ECS much more efficiently,
 *        but it serves its purpose for now
 *
 *
 */

Hotbar::Hotbar(Entity* entity, sf::Vector2f position, InventoryMenu* menu)
{
    this->i_entity = entity;
    this->i_menu   = menu;
    addComponent<Position>(position);
    addComponent<Sprite>("UI/ui.png");
}

Hotbar::~Hotbar()
{
    for(std::vector<Slot*>::iterator i = slots.begin(),
                e = slots.end(); i != e; ++i)
        delete (*i);

    delete h_text;
}

void Hotbar::initialize()
{
    assert(i_entity->hasComponent<Inventory>());
    i_i = &i_entity->getComponent<Inventory>();
    getComponent<Sprite>().getSprite().setTextureRect(sf::IntRect(0, 48, 49, 16));
    getComponent<Sprite>().getSprite().setScale(15, 10);

    sf::Vector2f slotPos(getComponent<Position>().getPosition().x + 75, getComponent<Position>().getPosition().y + 33);
    for(int i = 0; i < HOTBAR_SLOTS; i++)
    {
        slots.emplace_back(new Slot(slotPos, i_i));
        slotPos.x += 96; //16 * x-scale
    }

    selectionRect.setSize(sf::Vector2f(96, 96)); //16 * x-scale
    selectionRect.setOutlineColor(sf::Color::Black);
    selectionRect.setOutlineThickness(5.0f);
    selectionRect.setFillColor(sf::Color::Transparent);
    selectionRect.setPosition(slots[i_i->activeItem()]->getComponent<Sprite>().getSprite().getPosition());

    h_text = new TextDisplay("Current Item: None",
            sf::Vector2f(-225, 320), 20);
    h_text->initialize();

    Entity::initialize();
}

void Hotbar::updateSlots()
{
    for(int i = 0; i < HOTBAR_SLOTS; i++)
        slots.at(i)->setItem(i_entity->getComponent<Inventory>().item(i));

    for(int i = 0; i < HOTBAR_SLOTS; i++)
        slots.at(i)->setCount(i_entity->getComponent<Inventory>().amount(i));

    if (slots.at(i_i->activeItem())->item() != nullptr)
        h_text->setText("Current Item: " + slots.at(i_i->activeItem())->item()->name());
    else
        h_text->setText("Current Item: None");

    //check for tool equip/unequip
    auto* itm = slots.at(i_i->activeItem())->item();
    if (itm != nullptr)
    {
        if (!h_toolEquipped)
        {
            if (itm->type() == Item_Tool)
            {
                LevelManager::Instance()->getCurrentLevel().player()->equipItem(itm);
                h_toolEquipped = true;
            }
        }
        else
        {
            if (itm->type() != Item_Tool)
            {
                LevelManager::Instance()->getCurrentLevel().player()->unequipItem(itm);
                h_toolEquipped = false;
            }
        }
    }
}

void Hotbar::handleInput(sf::Keyboard::Key key)
{
    if (LevelManager::Instance()->getCurrentLevel().state() == GameState::PAUSE)
        return;

    uint8_t selection = key - 27;
    if (selection < HOTBAR_SLOTS)
    {
        if (i_i->activeItem() == selection)
        {
            i_entity->getComponent<Inventory>().activated(selection);
            slots[selection]->activateItem();
            i_menu->updateSlots();
            updateSlots();
            return;
        }
        i_i->setActive(selection);
        selectionRect.setPosition(slots[i_i->activeItem()]->getComponent<Sprite>().getSprite().getPosition());
    }
    if (selection == 44)
        i_i->activeItem() != 0 ? i_i->setActive(i_i->activeItem()-1) : i_i->setActive(HOTBAR_SLOTS - 1);
    else if (selection == 45)
        i_i->activeItem() != HOTBAR_SLOTS - 1 ? i_i->setActive(i_i->activeItem()+1) : i_i->setActive(0);
    selectionRect.setPosition(slots[i_i->activeItem()]->getComponent<Sprite>().getSprite().getPosition());

    updateSlots();
}

void Hotbar::handleInput(sf::Mouse::Button button)
{
    if (button == sf::Mouse::Left)
        updateSlots();
}

void Hotbar::render(sf::RenderWindow *window)
{
    Entity::render(window);

    for(auto &s : slots)
        s->render(window);

    window->draw(selectionRect);
    h_text->render(window);
}