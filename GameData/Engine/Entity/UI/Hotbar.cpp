#include "Hotbar.h"

/*
 *  Hotbar
 *
 *  NOTE: This could use the ECS much more efficiently,
 *        but it serves its purpose for now
 *
 *  TODO: Update Current Item Text
 *
 */

Hotbar::Hotbar(Entity* entity, sf::Vector2f position)
{
    this->i_entity = entity;
    addComponent<Position>(position);
    addComponent<Sprite>("UI/windowsheet.png");
}

void Hotbar::initialize()
{
    assert(i_entity->hasComponent<Inventory>());
    getComponent<Sprite>().getSprite().setTextureRect(sf::IntRect(0, 48, 48, 16));
    getComponent<Sprite>().getSprite().setScale(15, 10);

    Vector2f slotPos(getComponent<Position>().getPosition().x + 75, getComponent<Position>().getPosition().y + 20);
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

    selectionRect.setSize(sf::Vector2f(96, 96)); //16 * x-scale
    selectionRect.setOutlineColor(sf::Color::Black);
    selectionRect.setOutlineThickness(5.0f);
    selectionRect.setFillColor(sf::Color::Transparent);
    selectionRect.setPosition(slots[selectedSlot].sprite.getPosition());

    itemText = new TextDisplay("Current Item: None",
            sf::Vector2f(-225, 320), 20);
    itemText->initialize();

    Entity::initialize();
}

void Hotbar::handleInput(sf::Keyboard::Key key)
{
    uint selection = key - 27;
    if (selection < HOTBAR_SLOTS)
    {
        selectedSlot = selection;
        selectionRect.setPosition(slots[selectedSlot].sprite.getPosition());
        return;
    }
    if (selection == 44)
        selectedSlot != 0 ? selectedSlot-- : selectedSlot = HOTBAR_SLOTS - 1;
    else if (selection == 45)
        selectedSlot != HOTBAR_SLOTS - 1 ? selectedSlot++ : selectedSlot = 0;
    selectionRect.setPosition(slots[selectedSlot].sprite.getPosition());
}

void Hotbar::render(sf::RenderWindow *window)
{
    Entity::render(window);

    for(auto &s : slots)
        window->draw(s.sprite);

    window->draw(selectionRect);
    itemText->render(window);
}