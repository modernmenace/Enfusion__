#include "ItemPickup.h"
#include "../../Engine/Lvl/LevelManager.h"
#include "../../Engine/Component/Anim/AnimatedSprite.h"
#include "../../Engine/Component/Base/Collider.h"

ItemPickup::ItemPickup(Item *item, uint8_t count) : p_countText("", sf::Vector2f(0, 0), 20)
{
    p_item = item;
    p_count = count;
    create();
}

void ItemPickup::create()
{
    auto p_pos = LevelManager::Instance()->getCurrentLevel().player()->getComponent<Position>().getPosition();
    p_pos.x += LevelManager::Instance()->getCurrentLevel().player()->getComponent<AnimatedSprite>().bounds().width / 2;
    p_pos.y += LevelManager::Instance()->getCurrentLevel().player()->getComponent<AnimatedSprite>().bounds().height / 2;
    addComponent<Position>(p_pos);
    addComponent<Sprite>(p_item->icon());
    addComponent<Collider>(sf::FloatRect(p_pos.x, p_pos.y, 10, 10));
    if (p_count != 1)
    {
        p_countText.setText(std::to_string(p_count));
        p_countText.setPosition(sf::Vector2f(p_pos.x +(p_item->icon().getSize().x), p_pos.y + (p_item->icon().getSize().y)));
        p_countText.initialize();
    }
}

void ItemPickup::render(sf::RenderWindow* window)
{
    Entity::render(window);
    if (p_count != 1)
        p_countText.render(window);
}

void ItemPickup::handleInput(sf::Keyboard::Key key)
{
    Entity::handleInput(key);
    if (key == CONTROL("INTERACT"))
    {
        if (getComponent<Collider>().checkForCollision(LevelManager::Instance()->getCurrentLevel().player()))
            pickup();
    }
}

void ItemPickup::pickup()
{
    LevelManager::Instance()->getCurrentLevel().player()->getComponent<Inventory>().add(p_item, p_count);
    LevelManager::Instance()->getCurrentLevel().removeEntity(this);
    delete this;
}